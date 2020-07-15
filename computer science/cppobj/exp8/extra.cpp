#include<iostream>
#include<fstream>
#include<string>

using namespace std;

typedef long long int decimal;

class BinaryStreamWriter
{
public:
	BinaryStreamWriter()
	{

	}
	void open(string fileName)
	{
		_stream.open(fileName, ios::binary | ios::out);
	}
	void close()
	{
		_stream.close();
	}
	
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output,string data)
	{
		size_t length = data.length();
		const char* d = data.c_str();

		cout << d;

		output._stream.write(d, length + 1);
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output, char data)
	{
		output._stream.write((char*)& data, sizeof(char));
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output,int data)
	{
		output._stream.write((char*)&data, sizeof(int));
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output,short data)
	{
		output._stream.write((char*)&data, sizeof(short));
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output,long data)
	{
		output._stream.write((char*)& data, sizeof(long));
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output,decimal data)
	{
		output._stream.write((char*)& data, sizeof(decimal));
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output, float data)
	{
		output._stream.write((char*)& data, sizeof(float));
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output, double data)
	{
		output._stream.write((char*)& data, sizeof(double));
		return output;
	}
	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output,  long double data)
	{
		output._stream.write((char*)& data, sizeof(long double));
		return output;
	}

	
private:
	fstream _stream;
};

class BinaryStreamReader 
{
public:
	BinaryStreamReader()
	{
	}
	void open(string fileName)
	{
		_stream.open(fileName, ios::binary | ios::in);
	}
	void close()
	{
		_stream.close();
	}

	friend BinaryStreamReader& operator >> (BinaryStreamReader& input,string& obj)
	{
		obj.clear();
		char buffer = '\000';

		while (input._stream.read(&buffer, 1))
		{
			if (buffer == '\000')
			{
				break;
			}
			obj.push_back(buffer);

		}

		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input,char& obj)
	{
		input._stream.read((char*)& obj, sizeof(char));
		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input, short& obj)
	{
		input._stream.read((char*)& obj, sizeof(short));
		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input, int& obj)
	{
		input._stream.read((char*)& obj, sizeof(int));
		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input, long& obj)
	{
		input._stream.read((char*)& obj, sizeof(long));
		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input, decimal& obj)
	{
		input._stream.read((char*)& obj, sizeof(decimal));
		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input, float& obj)
	{
		input._stream.read((char*)& obj, sizeof(float));
		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input, double& obj)
	{
		input._stream.read((char*)& obj, sizeof(double));
		return input;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input,long double& obj)
	{
		input._stream.read((char*)& obj, sizeof(long double));
		return input;
	}
private:
	fstream _stream;
};

class Student
{
public:
	string id;
	string name;
	int age;

	friend BinaryStreamWriter& operator << (BinaryStreamWriter& output,const Student& data)
	{
		output << data.id << data.name << data.age;
		return output;
	}
	friend BinaryStreamReader& operator >> (BinaryStreamReader& input,Student& obj)
	{
		input >> obj.id >> obj.name >> obj.age;
		return input;
	}
	friend ostream& operator << (ostream& output,const Student& obj)
	{
		output << "id:" << obj.id << " name:" << obj.name << " age:" << obj.age << endl;
		return output;
	}
};

int main() 
{
	Student stud1 = { "10000","Zhang-San",20 };
	BinaryStreamWriter writer;
	writer.open("a.dat");
	writer << "hello world" << 1008782L << stud1;
	writer.close();
	
	string data;
	long data2;
	Student stud2;
	
	BinaryStreamReader reader;

	reader.open("a.dat");
	reader >> data >> data2 >> stud2;
	reader.close();

	cout << "data = " << data << ", data2 = " << data2 << endl
		<< stud2 << endl;

	system("pause");
	return 0;
}