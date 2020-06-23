#include<string>

using namespace std;

class student
{
public:
	student() {}
	student(int id, string name, double eng_grade, double lisanmath_grade, double cpp_grade)
	{
		this->id = id;
		this->name = name;
		this->eng_grade = eng_grade;
		this->lisanmath_grade = lisanmath_grade;
		this->cpp_grade = cpp_grade;
	}
	double sum();
	double average();
	void print();
	int get_stu_num()
	{
		return id;
	}
	double get_eng_grade()
	{
		return eng_grade;
	}
	double get_lisanmath_grade()
	{
		return lisanmath_grade;
	}
	double get_cpp_grade()
	{
		return cpp_grade;
	}
	bool set_stu_inf();
private:
	int id;
	string name;
	double eng_grade;
	double lisanmath_grade;
	double cpp_grade;

};

student *max_eng(student *arr_stu, int length);
student *max_lisanmath(student *arr_stu, int length);
student *max_cpp(student *arr_stu, int length);
student *max_sum(student *arr_stu, int length);
double get_ave_all(student *arr_stu, int length);