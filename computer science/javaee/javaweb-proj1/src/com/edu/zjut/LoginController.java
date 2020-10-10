package com.edu.zjut;

import java.io.IOException;
import java.io.PrintWriter;

public class LoginController extends javax.servlet.http.HttpServlet {
    protected void doPost(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        PrintWriter out = response.getWriter();
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        if ("zjut".equals(username) && "zjut".equals(password)){
            out.println("登录成功，欢迎你");
        } else {
            out.println("用户或者密码错误");
        }
    }

    protected void doGet(javax.servlet.http.HttpServletRequest request, javax.servlet.http.HttpServletResponse response) throws javax.servlet.ServletException, IOException {

    }
}
