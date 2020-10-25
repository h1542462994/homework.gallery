package cn.edu.zjut.filters;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.IOException;

public class AccessFilter extends HttpFilter {
    @Override
    public void doFilter(HttpServletRequest request, HttpServletResponse response, FilterChain chain) throws IOException, ServletException {
        System.out.println("Access Filter executed!");
        HttpSession session = request.getSession();
        if (session.getAttribute("user") == null &&
                !request.getRequestURI().contains("login.jsp") &&
                !request.getRequestURI().contains("register.jsp")
        ) {
            response.sendRedirect("login.jsp");
            return;
        }
        chain.doFilter(request, response);
    }
}
