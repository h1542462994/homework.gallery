package servlet;

import store.IStore;
import store.ServiceContainer;
import util.Web;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "MyServlet", urlPatterns = "/my")
public class MyServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (Web.isLogin(request)) {
            IStore store = ServiceContainer.get().store();
            request.setAttribute("userInfo", store.getInfo());
            Web.page(request, response, "my.jsp");
        } else {
            Web.redirect(response, getServletContext(), "");
        }
    }
}
