class triangle
{
public:
	triangle(double a = 1, double b = 1, double c = 1);

	double area();
	double length();
private:
	double get_p();
	double a;
	double b;
	double c;
};