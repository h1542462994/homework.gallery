package servlet;

import sql.DbConnector;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

@WebServlet(name = "BookServlet", urlPatterns = "")
public class BookServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        DbConnector connector = (DbConnector)getServletContext().getAttribute("connector");
        request.setCharacterEncoding("utf-8");
        response.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        try {
            PrintWriter out = response.getWriter();
            PreparedStatement statement = connector.getConnection().prepareStatement("select * from books");
            ResultSet set = statement.executeQuery();
            while(set.next()){
                out.print(set.getInt("bookid") + ",");
                out.print(set.getString("title"));
                out.print("<br>");
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }


    }
}
