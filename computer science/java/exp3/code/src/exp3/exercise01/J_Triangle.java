package exp3.exercise01;

import java.lang.Math;

/**
 * J_Triangle
 */
public class J_Triangle implements J_Shape {
    public J_Triangle() {
        this.a = 1.0;
        this.b = 1.0;
        this.c = 1.0;
    }

    public J_Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    private double a;
    private double b;
    private double c;

    public double getA() {
        return a;
    }

    public double getC() {
        return c;
    }

    public void setC(double c) {
        this.c = c;
    }

    public double getB() {
        return b;
    }

    public void setB(double b) {
        this.b = b;
    }

    public void setA(double a) {
        this.a = a;
    }

    @Override
    public double getPerimeter() {
        return a + b + c;
    }

    @Override
    public double getArea() {
        double p = getPerimeter() / 2.0;
        return Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }

}