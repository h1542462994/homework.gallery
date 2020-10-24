package cn.edu.zjut.action;

import com.opensymphony.xwork2.ActionSupport;

public class IndexAction extends ActionSupport {
    private Integer count;

    public IndexAction(){
        count = 0;
    }

    public String execute(){
        ++count;
        return SUCCESS;
    }
}
