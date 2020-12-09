package cn.edu.zjut.listener;

import cn.edu.zjut.event.EmailEvent;
import org.springframework.context.ApplicationEvent;
import org.springframework.context.ApplicationListener;

public class EmailNotifier implements ApplicationListener<ApplicationEvent> {
    @Override
    public void onApplicationEvent(ApplicationEvent event) {
        if (event instanceof EmailEvent) {
            EmailEvent emailEvent = (EmailEvent) event;
            System.out.println("需要发送邮件的接收地址:" + emailEvent.getAddress());
            System.out.println("需要发送邮件的邮件正文:" + emailEvent.getText());
        } else {
            System.out.println("容器本身的事件 " + event);
        }
    }
}
