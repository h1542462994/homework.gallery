package servlet;

import util.Web;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "QuestionServlet", urlPatterns = "/question")
public class QuestionServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if(Web.isLogin(request)){
            Web.page(request, response, "question.jsp");
        } else {
            Web.redirect(response, getServletContext(), "");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if(Web.isLogin(request)){
            int score = 0;
            String answer1 = request.getParameter("answer1");
            if("0".equals(answer1)){
                score += 10;
            }
            String answer2 = request.getParameter("answer2");
            if("0".equals(answer2)){
                score += 10;
            }

            String answer3 = String.join(",",request.getParameterValues("answer3"));
            if("0,1,2,3".equals(answer3)) {
                score += 20;
            }

            String answer4 = String.join(",",request.getParameterValues("answer4"));
            if("0,1,3,4".equals(answer4)){
                score += 20;
            }

            String answer5 = request.getParameter("answer5");
            if("氧".equals(answer5) || "O".equals(answer5)){
                score += 10;
            }

            String answer6 = request.getParameter("answer6");
            if("生态圈".equals(answer6)){
                score += 10;
            }

            String answer7 = request.getParameter("answer7");
            if(null == answer7){
                score += 10;
            }

            String answer8 = request.getParameter("answer8");
            if("0".equals(answer8)){
                score += 10;
            }

            request.setAttribute("score", score);
            Web.page(request, response, "question_result.jsp");
        } else {
            Web.redirect(response, getServletContext(), "");
        }
    }
}
