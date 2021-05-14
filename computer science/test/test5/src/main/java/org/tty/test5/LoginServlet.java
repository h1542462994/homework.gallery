package org.tty.test5;

import org.tty.test5.dao.UserDao;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "loginServlet", value = "/login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/login.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String username = req.getParameter("username");
        String password = req.getParameter("password");

        UserDao userDao = new UserDao();
        String result = "";
        result = "Hello," + username;

//        if (userDao.findByUsernameAndPassword(username, password).isEmpty()) {
//            result = "Operation Failed";
//        } else {
//            result = "Hello," + username;
//        }

        req.setAttribute("result", result);
        req.getRequestDispatcher("/result.jsp").forward(req, resp);
    }
}
