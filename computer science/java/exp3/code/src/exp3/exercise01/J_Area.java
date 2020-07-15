package exp3.exercise01;

public class J_Area{
    public static void main(String[] args){
        J_Shape shape;
        String templateString = "%s perimeter: %s area: %s";
        shape = new J_Circle(4);
        System.out.println(String.format(templateString, "circle(4)", shape.getPerimeter(), shape.getArea()));
        shape = new J_Rectange(3,4);
        System.out.println(String.format(templateString, "rectangle(3,4)", shape.getPerimeter(), shape.getArea()));
        shape = new J_Triangle(3,4,5);
        System.out.println(String.format(templateString, "triangle(3,4,5)", shape.getPerimeter(), shape.getArea()));
    }
}