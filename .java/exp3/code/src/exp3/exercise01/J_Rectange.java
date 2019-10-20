package exp3.exercise01;

public class J_Rectange implements J_Shape {
    public J_Rectange(){
        this.width = 1.0;
        this.height = 1.0;
    }
    public J_Rectange(double width,double height){
        this.width = width;
        this.height = height;
    }

    private double width;
    private double height;

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

        @Override
    public double getPerimeter() {
        return 2*(this.width + this.height);
    }

    @Override
    public double getArea() {
        return this.width * this.height;
    }

    
}