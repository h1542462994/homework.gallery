package cn.edu.zjut;

import cn.edu.zjut.model.*;
import javax.servlet.*;
import java.io.*;

public class LoginController extends javax.servlet.http.HttpServlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out = response.getWriter();
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        int type = Integer.parseInt(request.getParameter("type"));
        UserBean user = new UserBean();
        user.setUsername(username);
        user.setPassword(password);
        user.setType(type);

        if (checkUser(user)){
            request.setAttribute("USER", user);
            RequestDispatcher dispatcher = request.getRequestDispatcher("/loginSuccess.jsp");
            dispatcher.forward(request, response);
        } else {
            // warning: the prefix should be replaced as a variable from applicationContext.
            response.sendRedirect("/javaweb_proj1/loginFailed.jsp");
        }
    }

    boolean checkUser(UserBean user){
        if(user.getType() == UserBean.ADMIN && "zjut".equals(user.getUsername()) &&
                "zjut".equals(user.getPassword())) {
            return true;
        } else {
            return false;
        }
    }

    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {

    }
}
