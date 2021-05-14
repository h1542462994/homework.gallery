package org.tty.test3.dao;

import org.easymock.EasyMock;
import org.tty.test3.entity.User;

public class MockUserDao implements IUserDao {
    public void setInMemoryUserSet(InMemoryUserSet inMemoryUserSet) {
        this.inMemoryUserSet = inMemoryUserSet;
    }

    private InMemoryUserSet inMemoryUserSet;


    @Override
    public boolean addUser(User user) {
        if (!verifyUsername(user.getUsername())) {
            inMemoryUserSet.addUser(user);
            return true;
        }
        return false;
    }

    @Override
    public boolean verifyUsername(String username) {
        return inMemoryUserSet.verifyUserName(username);
    }

    @Override
    public boolean verifyPassword(String username, String password) {
        return inMemoryUserSet.verifyUserNameAndPassword(username, password);
    }


    /**
     * 获取代理类
     * @return 实际代理类
     */
    public static IUserDao getProxy() {
        MockUserDao realUserDao = new MockUserDao();
        realUserDao.setInMemoryUserSet(new InMemoryUserSet());
        return realUserDao;
    }

    public static IUserDao getMocked(String username, String password) {
        IUserDao realUserDao = getProxy();
        User wrappedUser = new User();
        wrappedUser.setUsername(username);
        wrappedUser.setPassword(password);

        IUserDao mockUserDao = EasyMock.createMock(IUserDao.class);
        EasyMock.expect(mockUserDao.addUser(wrappedUser))
                .andReturn(realUserDao.addUser(wrappedUser));
        EasyMock.expect(mockUserDao.verifyUsername(wrappedUser.getUsername()))
                .andReturn(realUserDao.verifyUsername(wrappedUser.getUsername()));
        EasyMock.expect(mockUserDao.verifyPassword(wrappedUser.getUsername(), wrappedUser.getPassword()))
                .andReturn(realUserDao.verifyPassword(wrappedUser.getUsername(), wrappedUser.getPassword()));
        EasyMock.replay(mockUserDao);

        return mockUserDao;
    }
}
