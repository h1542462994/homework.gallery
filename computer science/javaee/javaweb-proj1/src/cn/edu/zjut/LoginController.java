package cn.edu.zjut;

import cn.edu.zjut.dao.DbUserDao;
import cn.edu.zjut.dao.MockUserDao;
import cn.edu.zjut.dao.UserDao;
import cn.edu.zjut.model.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class LoginController extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out = response.getWriter();
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        // warning: check the type of the input.
        int type = Integer.parseInt(request.getParameter("type"));
        UserBean user = new UserBean();
        user.setUsername(username);
        user.setPassword(password);
        user.setType(type);

        if (checkUser(user)) {
            request.setAttribute("USER", user);
            RequestDispatcher dispatcher = request.getRequestDispatcher("/loginSuccess.jsp");
            dispatcher.forward(request, response);
        } else {
            // warning: the prefix should be replaced as a variable from applicationContext.
            response.sendRedirect("/javaweb_proj1/loginFailed.jsp");
        }
    }

    boolean checkUser(UserBean user){
        UserDao userDao = new DbUserDao();
        return userDao.searchUser(user);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws javax.servlet.ServletException, IOException {

    }
}
