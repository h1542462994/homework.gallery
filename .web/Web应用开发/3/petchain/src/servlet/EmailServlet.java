package servlet;

import store.IStore;
import store.ServiceContainer;
import util.Web;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

//config by web.xml
public class EmailServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        ServletConfig config = getServletConfig();
        String username = config.getInitParameter("username");
        String email = config.getInitParameter("email");

        Web.html(response);
        PrintWriter writer = response.getWriter();
        writer.print("姓名：" + username + "<br>");
        writer.print("邮箱：" + email);
    }
}
