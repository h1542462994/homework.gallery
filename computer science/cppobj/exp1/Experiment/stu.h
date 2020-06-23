#pragma once
#include<string>
using namespace std;

namespace cht 
{
	class stu 
	{
	public:
		stu(){}
		~stu() {}
		int id;
		string name;
		double grade;
		static friend istream &  operator >> (istream & in, stu & arg) 
		{
			in >> arg.id >> arg.name >> arg.grade;
			return in;
		}
		static friend ostream & operator << (ostream & out, stu & arg)
		{
			out << "id:" << arg.id << " name:" << arg.name << " grade:" << arg.grade << endl;
			return out;
		}
	};
}