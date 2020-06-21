package util;

import dao.LoginState;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

public class Web {
    public static void page(HttpServletRequest request, HttpServletResponse response, String url) throws ServletException, IOException {
        request.getRequestDispatcher(url).forward(request, response);
    }

    public static void redirect(HttpServletResponse response, ServletContext context, String page) throws IOException {
        response.sendRedirect(context.getContextPath() + page);
    }

    public static void html(HttpServletResponse response){
        response.setContentType("text/html;charset=utf-8");
    }

    public static boolean isLogin(HttpServletRequest request){
        HttpSession session = request.getSession();
        LoginState loginState = (LoginState) session.getAttribute("loginState");
        return loginState.isState();
    }
}
