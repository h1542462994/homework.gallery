package servlet;

import dao.Pet;
import ext.validation.Validator;
import request.AddDogRequest;
import store.IStore;
import store.ServiceContainer;
import util.Checker;
import util.Web;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "AddDogServlet", urlPatterns = "/add_dog")
public class AddDogServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (Web.isLogin(request)){
            AddDogRequest addDogRequest = new AddDogRequest();
            request.setAttribute("addDogRequest", addDogRequest);
            Web.page(request, response, "/add_dog.jsp");
        } else {
            Web.redirect(response, getServletContext(), "");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {


        if (Web.isLogin(request)){
            AddDogRequest addDogRequest = new AddDogRequest();
            request.setAttribute("addDogRequest", addDogRequest);
            try {
                Validator.fill(addDogRequest, request);
                //addDogRequest.fill(request);
                boolean valid = true;
                String nameError = Checker.checkName(addDogRequest.getName());
                if(nameError != null){
                    valid = false;
                    addDogRequest.setNameError(nameError);
                }
                String batchError = Checker.checkBatch(addDogRequest.getBatch());
                if(batchError != null) {
                    valid = false;
                    addDogRequest.setBatchError(batchError);
                }

                if(!valid){

                    Web.page(request, response, "/add_dog.jsp");
                } else {
                    IStore store = ServiceContainer.get().store();
                    store.getPets().add(Pet.fromRequest(addDogRequest));
                    Web.redirect(response, getServletContext(), "");
                }
            } catch (IllegalAccessException | NumberFormatException e) {
                e.printStackTrace();
                addDogRequest.setNameError("未知的异常");
                Web.page(request, response, "/add_dog.jsp");
            }
        } else {
            Web.redirect(response, getServletContext(), "");
        }

    }
}
