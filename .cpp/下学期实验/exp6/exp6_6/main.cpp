#include<iostream>
#include"declare.h"
using namespace std;

int main()
{
    do
    {
        Employee* employee = NULL;
        cout << "请输入员工的类别信息,包括(1:manager,2:technician,3:salesman,4:salesmanager,<=0:退出):" << endl;
        int t;
        cin >> t;
        if (t <= 0)
        {
            break;
        }
        else if(t == 1)
        {
            employee = &Manager();
            //employee->setState();
        }
        else if (t == 2)
        {
            employee =  &Technician();

        }
        else if (t == 3)
        {
            employee =  &Salesman();
        }
        else if (t == 4)
        {
            employee =  &SalesManager();
        }
        else
        {
            cout << "非法的数字" << endl;
        }
        if (employee!=NULL)
        {
            employee->setState();
            employee->pay();
            employee->display();
            //delete employee;
            employee = NULL;
        }
    } while (true);


    return 0;
}