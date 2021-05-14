package org.tty.test5;

import org.hibernate.Session;
import org.hibernate.Transaction;
import org.tty.test5.dao.SessionUtil;
import org.tty.test5.dao.UserDao;
import org.tty.test5.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "registerServlet", value = "/register")
public class RegisterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.getRequestDispatcher("/register.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        resp.setCharacterEncoding("utf-8");

        String username = req.getParameter("username");
        String password =req.getParameter("password");

        User user = new User();
        user.setUsername(username);
        user.setPassword(password);

        UserDao userDao = new UserDao();
        PrintWriter out = resp.getWriter();
        String result = "";

//        Session session = SessionUtil.getSession();
//
//        Transaction transaction = session.beginTransaction();
//
//        if (!userDao.findByUserName(username).isEmpty()) {
//            result = "Operation Failed";
//        } else {
//            userDao.save(user);
//            result = "Register Success," + user.getUsername();
//        }
//        transaction.commit();

        result = "Register Success," + user.getUsername();

        req.setAttribute("result", result);
        req.getRequestDispatcher("/result.jsp").forward(req, resp);
    }
}
