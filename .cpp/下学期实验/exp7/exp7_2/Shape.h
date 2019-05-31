class Shape
{
public:
    virtual ~Shape(){}
    virtual void display() const {}
    virtual double area() const = 0;
    
};