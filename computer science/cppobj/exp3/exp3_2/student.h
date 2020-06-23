class student
{
public:
	student(int id, double grade)
	{
		this->id = id;
		this->grade = grade;
	}

	static student *max(student *arr_stu, int length);
	int id;
	double grade;
};