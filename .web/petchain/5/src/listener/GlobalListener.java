package listener;

import org.apache.catalina.connector.Connector;
import sql.DbConnector;
import sql.DbSettings;

import javax.servlet.ServletContext;
import javax.servlet.ServletContextEvent;
import javax.servlet.ServletContextListener;
import javax.servlet.annotation.WebListener;
import java.sql.SQLException;

@WebListener()
public class GlobalListener implements ServletContextListener {

    public GlobalListener() {
    }

    public void contextInitialized(ServletContextEvent event) {
        try{
            ServletContext context = event.getServletContext();
            DbSettings settings = new DbSettings();
            settings.setDriver(context.getInitParameter("db-driver"));
            settings.setUrl(context.getInitParameter("db-url"));
            settings.setUsername(context.getInitParameter("db-user"));
            settings.setPassword(context.getInitParameter("db-password"));
            DbConnector connector = new DbConnector(settings);
            context.setAttribute("connector", connector);
        } catch (SQLException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void contextDestroyed(ServletContextEvent event) {
    }

}
