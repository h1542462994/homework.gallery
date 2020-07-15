package request;

import ext.annotation.Rename;
import jdk.nashorn.internal.ir.annotations.Ignore;

import javax.servlet.http.HttpServletRequest;

public class AddDogRequest {
    private String name;
    @Ignore
    private String nameError;
    private String batch;
    @Ignore
    private String batchError;
    private String imageUrl;
    @Ignore
    private String imageUrlError;
    @Rename(name = "attribute-0")
    private int attribute_0;
    @Rename(name = "attribute-1")
    private int attribute_1;
    @Rename(name = "attribute-2")
    private int attribute_2;
    @Rename(name = "attribute-3")
    private int attribute_3;
    @Rename(name = "attribute-4")
    private int attribute_4;
    @Rename(name = "attribute-5")
    private int attribute_5;
    @Rename(name = "attribute-6")
    private int attribute_6;
    @Rename(name = "attribute-7")
    private int attribute_7;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getNameError() {
        return nameError;
    }

    public void setNameError(String nameError) {
        this.nameError = nameError;
    }

    public String getBatch() {
        return batch;
    }

    public void setBatch(String batch) {
        this.batch = batch;
    }

    public String getBatchError() {
        return batchError;
    }

    public void setBatchError(String batchError) {
        this.batchError = batchError;
    }

    public String getImageUrl() {
        return imageUrl;
    }

    public void setImageUrl(String imageUrl) {
        this.imageUrl = imageUrl;
    }

    public String getImageUrlError() {
        return imageUrlError;
    }

    public void setImageUrlError(String imageUrlError) {
        this.imageUrlError = imageUrlError;
    }

    public int getAttribute_0() {
        return attribute_0;
    }

    public void setAttribute_0(int attribute_0) {
        this.attribute_0 = attribute_0;
    }

    public int getAttribute_1() {
        return attribute_1;
    }

    public void setAttribute_1(int attribute_1) {
        this.attribute_1 = attribute_1;
    }

    public int getAttribute_2() {
        return attribute_2;
    }

    public void setAttribute_2(int attribute_2) {
        this.attribute_2 = attribute_2;
    }

    public int getAttribute_3() {
        return attribute_3;
    }

    public void setAttribute_3(int attribute_3) {
        this.attribute_3 = attribute_3;
    }

    public int getAttribute_4() {
        return attribute_4;
    }

    public void setAttribute_4(int attribute_4) {
        this.attribute_4 = attribute_4;
    }

    public int getAttribute_5() {
        return attribute_5;
    }

    public void setAttribute_5(int attribute_5) {
        this.attribute_5 = attribute_5;
    }

    public int getAttribute_6() {
        return attribute_6;
    }

    public void setAttribute_6(int attribute_6) {
        this.attribute_6 = attribute_6;
    }

    public int getAttribute_7() {
        return attribute_7;
    }

    public void setAttribute_7(int attribute_7) {
        this.attribute_7 = attribute_7;
    }

    public static AddDogRequest fromRequest(HttpServletRequest request){
        AddDogRequest addDogRequest = new AddDogRequest();
        addDogRequest.fill(request);

        return addDogRequest;
    }

    public void fill(HttpServletRequest request){
        setName(request.getParameter("name"));
        setBatch(request.getParameter("batch"));
        setImageUrl(request.getParameter("imageUrl"));
        setAttribute_0(Integer.parseInt(request.getParameter("attribute-0")));
        setAttribute_1(Integer.parseInt(request.getParameter("attribute-1")));
        setAttribute_2(Integer.parseInt(request.getParameter("attribute-2")));
        setAttribute_3(Integer.parseInt(request.getParameter("attribute-3")));
        setAttribute_4(Integer.parseInt(request.getParameter("attribute-4")));
        setAttribute_5(Integer.parseInt(request.getParameter("attribute-5")));
        setAttribute_6(Integer.parseInt(request.getParameter("attribute-6")));
        setAttribute_7(Integer.parseInt(request.getParameter("attribute-7")));
    }
}
