package servlet;


import com.mysql.cj.Session;
import dao.PetInit;
import util.Web;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;

@WebServlet(name = "PetInitServlet", urlPatterns = "/pet_init")
public class PetInitServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (Web.isLogin(request)){
            PetInit petInit = new PetInit();
            HttpSession session = request.getSession();
            session.setAttribute("petInit", petInit);
            Web.page(request, response, "/pet_init.jsp");
        } else {
            Web.redirect(response, getServletContext(), "");
        }
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        if (Web.isLogin(request)) {
            HttpSession session = request.getSession();
            PetInit petInit = (PetInit) session.getAttribute("petInit");

            try {
                int number = Integer.parseInt(request.getParameter("number"));
                if(number < 0){
                    petInit.setGuessResult("数字小于0");
                } else if(number >= 100){
                    petInit.setGuessResult("数字大于99");
                } else {
                    petInit.distribute(); // 进行概率上的调整
                    if(number == petInit.getNumber()){
                        petInit.setGuessed(true);
                        petInit.setGuessResult("恭喜你猜对了！");
                        //执行猜对后的逻辑
                    } else if(number < petInit.getNumber()){
                        petInit.setGuessResult("太小了");
                    } else {
                        petInit.setGuessResult("太大了");
                    }
                }
            } catch (NumberFormatException e){
                petInit.setGuessResult("不是数字");
            }
            Web.page(request, response, "/pet_init.jsp");
        } else {
            Web.redirect(response, getServletContext(), "");
        }
    }
}
