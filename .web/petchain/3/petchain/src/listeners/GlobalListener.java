package listeners;

import com.mysql.cj.Session;
import dao.LoginState;
import org.apache.catalina.SessionListener;
import store.ServiceContainer;

import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import javax.servlet.http.*;

@WebListener()
public class GlobalListener implements ServletContextListener, HttpSessionListener, HttpSessionAttributeListener {

    public GlobalListener() {
    }

    @Override
    public void contextInitialized(ServletContextEvent event) {
        ServiceContainer.create(event.getServletContext());
    }

    @Override
    public void contextDestroyed(ServletContextEvent event) {

    }

    @Override
    public void sessionCreated(HttpSessionEvent event) {
        LoginState loginState = new LoginState();
        HttpSession session = event.getSession();
        session.setAttribute("loginState", loginState);
    }
}
