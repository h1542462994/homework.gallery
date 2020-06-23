class complex
{
public:
	complex(double real = 0, double image = 0);
	complex(const complex & obj);
	~complex();

	void display();

private:
	double real;
	double image;
};