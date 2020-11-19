#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    cout << "即将创建子进程notepad.exe" << endl;

    STARTUPINFO startupinfo; // 初始化信息
    PROCESS_INFORMATION processInformation; // 进程信息
    ZeroMemory(&startupinfo, sizeof(startupinfo)); // 初始化内存空间
    ZeroMemory(&processInformation, sizeof(processInformation)); // 初始化内存空间

    if(CreateProcess(nullptr,(LPSTR) L"notepad.exe",nullptr,nullptr,false,CREATE_NEW_CONSOLE,nullptr,nullptr,&startupinfo,&processInformation)){
        cout << "创建进程成功" << endl;
    } else {
        cout << "创建进程失败" << endl;
        return -1;
    }

    cout << "按回车以关闭子进程" << endl;
    string temp;
    cin >> temp;

    // 终止子进程
    TerminateProcess(processInformation.hProcess, 0);

    cout << "子进程已结束" << endl;

    return 0;
}
