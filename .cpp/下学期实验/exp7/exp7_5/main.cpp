#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    Person(string id = "", string name = "", double worktime = 0)
        :id(id), name(name), worktime(worktime)
    {
    }

    virtual ~Person()
    {
    }

    virtual void setState() = 0;
    virtual void display() const
    {
        cout << "姓名：" << name << endl;
    }

    string getId() const
    {
        return id;
    }
    void setId(string id)
    {
        this->id = id;
    }
    string getName() const
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    int getWorktime() const
    {
        return worktime;
    }
    void setWorktime(double worktime)
    {
        this->worktime = worktime;
    }

private:
    string id;
    string name;
    double worktime;
};

class Teacher :public Person
{
public:
    Teacher(string id = "", string name = "", double worktime = 0, string title = "", string school = "", int wages = 0) :Person(id, name, worktime), title(title), school(school), wages(wages)
    {
    }
    virtual ~Teacher() override
    {
    }
    virtual void display() const override
    {
        cout << "该教师的信息" << endl;
        Person::display();
        cout << "教师工号：" << getId() << endl
                << "所属学院：" << school << endl
            << "职称：" << title << endl
            << "每日教学时长" << getWorktime() << endl
            << "工资" << wages << endl;
    }
    virtual void setState() override
    {
        cout << "*教师管理子系统*" << endl
            << "----------------" << endl;
        cout << "请输入教师工号：";
        string id, name;
        double worktime;
        cin >> id;
        setId(id);
        cout << "请输入教师姓名：";
        cin >> name;
        setName(name);
        cout << "请输入教学时长：";
        cin >> worktime;
        setWorktime(worktime);
        cout << "请输入所在学院：";
        cin >> school;
        cout << "请输入职称：";
        cin >> title;
        cout << "请输入工资：";
        cin >> wages;
    }


    string getTitle() const
    {
        return title;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    string getSchool() const
    {
        return school;
    }
    void setSchool(string school)
    {
        this->school = school;
    }
    int getWages() const
    {
        return wages;
    }
    void setWages(int wages)
    {
        this->wages = wages;
    }


private:
    string title;
    string school;
    int wages;
};

class Student :public Person
{
public:
    Student(string id = "", string name = "", double worktime = 0, string school = "", string post = "") :Person(id, name, worktime), school(school), post(post)
    {
    }

    virtual ~Student() override
    {
    }

    virtual void display() const override
    {

        cout << "该学生的信息：" << endl;
        Person::display();
        cout << "学生学号：" << getId() << endl
            << "所属学院：" << school << endl
            << "职务：" << post << endl
            << "每日学习时长：" << getWorktime() << endl;
    }

    virtual void setState() override
    {
        cout << "*学生管理子系统*" << endl
            << "----------------" << endl;
        string id, name;
        double worktime;
        cout << "请输入学生学号：";
        cin >> id;
        setId(id);
        cout << "请输入学生姓名：";
        cin >> name;
        setName(name);
        cout << "请输入学习时长：";
        cin >> worktime;
        setWorktime(worktime);
        cout << "请输入所属学院：";
        cin >> school;
        cout << "请输入所担任的班级职务：";
        cin >> post;
    }

    string getSchool() const
    {
        return school;
    }
    void setSchool(string school)
    {
        this->school = school;
    }
    string getPost() const
    {
        return post;
    }
    void setPost(string post)
    {
        this->post = post;
    }


private:
    string school;
    string post;
};

class Employee :public Person
{
public:
    Employee(string id = "", string name = "", double worktime = 0, string department = "", int wages = 0) :Person(id, name, worktime), department(department), wages(wages)
    {
    }
    virtual ~Employee() override
    {
    }

    virtual void display() const override
    {
        cout << "该职工的信息" << endl;
        Person::display();
        cout << "职工工号：" << getId() << endl
            << "职工姓名：" << getName() << endl
            << "所属部门：" << department << endl
            << "每日工作时长：" << getWorktime() << endl
            << "工资：" << wages << endl;
    }

    virtual void setState() override
    {
        cout << "*职工管理子系统*" << endl
            << "----------------" << endl;
        string id, name;
        double worktime;
        cout << "请输入职工工号：";
        cin >> id;
        setId(id);
        cout << "请输入职工姓名：";
        cin >> name;
        setName(name);
        cout << "请输入工作时长：";
        cin >> worktime;
        setWorktime(worktime);
        cout << "请输入所属部门：";
        cin >> department;
        cout << "请输入工资：";
        cin >> wages;
    }

    string getDepartment() const
    {
        return department;
    }
    void setDepartment(string department)
    {
        this->department = department;
    }
    int getWages() const
    {
        return wages;
    }
    void setWages(int wages)
    {
        this->wages = wages;
    }

private:
    string department;
    int wages;
};

int main()
{
    Person* pPerson = NULL;
    do
    {
        cout << "浙江工业大学 人工信息平台" << endl
            << "***********************" << endl
            << "1.学生信息管理" << endl
            << "2.教师信息管理" << endl
            << "3.职工信息管理" << endl
            << "4.退出菜单" << endl;

        int num;
        cin >> num;
        if (num == 4)
        {
            break;
        }
        else if (num == 1)
        {
            pPerson = new Student();
        }
        else if (num == 2)
        {
            pPerson = new Teacher();
        }
        else if (num == 3)
        {
            pPerson = new Employee();
        }
        else
        {
            cout << "输入错误！" << endl;
            continue;
        }

        pPerson->setState();

        cout << endl;

        pPerson->display();

        delete pPerson;
        cout << endl;
    } while (true);

    return 0;
}