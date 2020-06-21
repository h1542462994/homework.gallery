package servlet;

import dao.LoginState;
import dao.UserPassport;
import ext.validation.Validator;
import store.IStore;
import store.ServiceContainer;
import util.Web;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet(name = "LoginServlet", urlPatterns = "/login")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        HttpSession session = request.getSession();
        LoginState loginState = (LoginState) session.getAttribute("loginState");
        loginState.getPassport().clearError();

        Web.page(request, response, "login.jsp");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            UserPassport passport = new UserPassport();
            Validator.fill(passport, request);

            IStore store = ServiceContainer.get().store();
            boolean valid = store.login(passport);

            HttpSession session = request.getSession();

            LoginState loginState = (LoginState) session.getAttribute("loginState");;

            loginState.setPassport(passport);
            if(!valid){
                loginState.setState(false);
                //Web.page(request, response, "login.jsp");
                Web.page(request, response, "/error.jsp");
            } else {
                loginState.setState(true);
                Web.redirect(response, getServletContext(), "/my");
            }
        } catch (IllegalAccessException e){
            e.printStackTrace();
            response.sendError(500, "网页异常");
        }
    }
}
