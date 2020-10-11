package cn.edu.zjut;

import javax.servlet.*;
import javax.servlet.http.*;
import cn.edu.zjut.model.*;

import java.io.IOException;

public class RegisterController extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");

    }
}
