#include<iostream>
#include<fstream>
using namespace std;

class Student 
{
public:
	char id[20];
	char name[20];
	float grade;

	friend ostream& operator << (ostream& output,const Student& obj)
	{	
		cout << "学号:" << obj.id << endl
			<< "姓名:" << obj.name << endl
			<< "成绩:" << obj.grade << endl;
		return output;
	}
};

int main()
{
	Student stu[] = { {"201800000001","Zhang-San",89.5},{"201800000002","Li-Si",99.5},{"201800000003","Wang-Wu",72} };
	Student cache[3];

	fstream f;
	f.open("stu.dat", ios::out | ios::binary);
	for (int i = 0; i < 3; i++)
	{
		f.write((char*)(stu + i), sizeof(Student));
	}
	f.close();

	f.open("stu.dat", ios::in | ios::binary);
	for (int i = 0; i < 3; i++)
	{
		f.read((char*)(stu + i), sizeof(Student));
	}
	f.close();
	for (int i = 0; i < 3; i++)
	{
		cout << stu[i] << endl;
	}


	//system("pause");
	return 0;
}