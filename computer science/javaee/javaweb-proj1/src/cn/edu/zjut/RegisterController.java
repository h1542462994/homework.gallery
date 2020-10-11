package cn.edu.zjut;

import javax.servlet.*;
import javax.servlet.http.*;

import cn.edu.zjut.dao.DbUserDao;
import cn.edu.zjut.dao.UserDao;
import cn.edu.zjut.model.*;

import java.io.IOException;
import java.io.PrintWriter;

public class RegisterController extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out = response.getWriter();
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        int type = Integer.parseInt(request.getParameter("type"));
        UserBean user = new UserBean();
        user.setUsername(username);
        user.setPassword(password);
        user.setType(type);

        UserDao userDao = new DbUserDao();
        if (userDao.insertUser(user)){
            out.println("注册成功，欢迎" + username + "!");
        } else {
            out.println("注册失败");
        }
    }
}
