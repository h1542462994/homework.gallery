package org.tty.test2.foundation;

import org.easymock.EasyMock;
import org.tty.test2.LoginServlet;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;

public class MockFactory {
    public static RequestDispatcher mockRequestDispatcher() {
        ResultHook.getInstance().setValue("no_init");
        return new RequestDispatcher() {
            @Override
            public void forward(ServletRequest request, ServletResponse response) throws ServletException, IOException {

                ResultHook.getInstance().setValue("ok");
            }

            @Override
            public void include(ServletRequest request, ServletResponse response) throws ServletException, IOException {

            }
        };
    }

    public static ServletContext mockServletContext() {
        ServletContext servletContext = EasyMock.createMock(ServletContext.class);
        EasyMock.expect(servletContext.getNamedDispatcher("dispatcher")).andReturn(mockRequestDispatcher());
        EasyMock.replay(servletContext);
        return servletContext;
    }

    public static ServletConfig mockServletConfig() {
        ServletConfig servletConfig = EasyMock.createMock(ServletConfig.class);
        EasyMock.expect(servletConfig.getServletContext()).andReturn(mockServletContext());
        EasyMock.replay(servletConfig);
        return servletConfig;
    }

    public static LoginServlet mockLoginServlet() {
        LoginServlet loginServlet = EasyMock.createMock(LoginServlet.class);
        EasyMock.expect(loginServlet.getServletContext()).andReturn(mockServletContext());

        EasyMock.replay(loginServlet);
        return loginServlet;
    }

    public static HttpServletRequest mockHttpServletRequest(HashMap<String, String> dic) {
        HttpServletRequest httpServletRequest = EasyMock.createMock(HttpServletRequest.class);
        dic.forEach((key, value) -> {
            EasyMock.expect(httpServletRequest.getParameter(key)).andReturn(value);
        });
        EasyMock.expect(httpServletRequest.getMethod()).andReturn("POST");
        EasyMock.replay(httpServletRequest);
        return httpServletRequest;
    }

    public static HttpServletResponse mockHttpServletResponse() {
        HttpServletResponse httpServletResponse = EasyMock.createMock(HttpServletResponse.class);
        EasyMock.replay(httpServletResponse);
        return httpServletResponse;
    }

}
