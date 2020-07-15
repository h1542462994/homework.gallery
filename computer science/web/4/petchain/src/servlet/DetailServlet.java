package servlet;

import dao.Pet;
import store.IStore;
import store.ServiceContainer;
import util.Web;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "DetailServlet", urlPatterns = "/detail")
public class DetailServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            String id = request.getParameter("id");
            IStore store = ServiceContainer.get().store();
            Pet pet = store.getPets().find(id);
            if (pet == null) {
                Web.redirect(response, getServletContext(), "");
            } else {
                request.setAttribute("pet", pet);
                Web.page(request, response, "/detail.jsp");
            }
        } catch (NumberFormatException e){
          Web.redirect(response, getServletContext(), "");
        }
    }
}
