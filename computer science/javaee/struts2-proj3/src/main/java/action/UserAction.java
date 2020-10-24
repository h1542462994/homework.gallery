package action;

import bean.ShoppingCart;
import bean.UserBean;
import bean.UserRegisterBean;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;
import org.apache.struts2.ServletActionContext;
import org.apache.struts2.interceptor.ServletRequestAware;
import org.apache.struts2.interceptor.ServletResponseAware;
import org.apache.struts2.util.ServletContextAware;
import service.UserService;

import javax.naming.spi.DirObjectFactory;
import javax.servlet.ServletContext;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.util.Map;

public class UserAction extends ActionSupport {
    private UserRegisterBean loginUser;
    private Map<String, Object> session;

    public UserAction() {
        System.out.println("创建了一个UserAction类对象");
    }

    public UserRegisterBean getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(UserRegisterBean loginUser) {
        this.loginUser = loginUser;
    }

    private final static String REQUEST = "request";
    private final static String COUNTER = "counter";
    private final static String FAIL = "fail";
    private final static String USER = "user";
    private final static String TIP = "tip";

    public String login() {
        ActionContext actionContext = ActionContext.getContext();
        session = actionContext.getSession();
        UserService userService = new UserService();
        if (userService.login(loginUser)) {
            session.put(USER, loginUser.getAccount());
            return SUCCESS;
        }
        return FAIL;
    }

    public String register() {
        UserService userService = new UserService();
        if (userService.register(loginUser).isPass()) {
            return SUCCESS;
        }
        return FAIL;
    }


//    public void validateLogin() {
//        String account = loginUser.getAccount();
//        String password = loginUser.getPassword();
//        if (account == null || account.equals("")) {
//            this.addFieldError("loginUser.account", getText("login.account.error"));
//        }
//        if (password == null || password.equals("")) {
//            this.addFieldError("loginUser.password", getText("login.password.error"));
//        }
//    }

//    public void validateRegister(){
//        String emailRegular = "^[_A-Za-z0-9-\\+]+(\\.[_A-Za-z0-9-]+)*@[A-Za-z0-9-]+(\\.[A-Za-z0-9]+)*(\\.[A-Za-z]{2,})$";
//        //begins.. account
//        String account = loginUser.getAccount();
//        if (account == null || account.equals("")) {
//            this.addFieldError("loginUser.account", getText("login.account.error"));
//        }
//        String password = loginUser.getPassword();
//        if(password == null || password.equals("")) {
//            this.addFieldError("loginUser.password", getText("login.password.error"));
//        }
//        String repassword = loginUser.getRepassword();
//        if(repassword == null || !repassword.equals(password)) {
//            this.addFieldError("loginUser.repassword", getText("login.repassword.error"));
//        }
//        String name = loginUser.getName();
//        if (name == null || name.equals("")) {
//            this.addFieldError("loginUser.name", getText("login.name.error"));
//        }
//        String address = loginUser.getAddress();
//        if (address == null || address.equals("")) {
//            this.addFieldError("loginUser.address"), getText("login.address.error");
//        }
//        String phone = loginUser.getPhone();
//        if( phone == null || phone.length() < 5 || phone.length() > 15){
//            this.addFieldError("loginUser.phone", getText("login.phone.error"));
//        }
//
//        String email = loginUser.getEmail();
//        if(email == null || !email.matches(emailRegular) {
//            this.addFieldError("loginUser.email", getText("login.email.error"));
//        }
//    }
}
