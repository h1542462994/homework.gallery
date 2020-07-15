package exp3.exercise02;

public class J_Circle extends J_Shape{
    static final double PI = 3.14;

    public J_Circle(){
        this.radius = 1.0;
    }

    public J_Circle(double radius){
        this.radius = radius;
    }

    private double radius;

    public double getRadius(){
        return this.radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public double getPerimeter() {
        return 2*PI*this.radius;
    }

    @Override
    public double getArea() {
        return PI*this.radius*this.radius;
    }

}