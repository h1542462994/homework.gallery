// Process.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// @environ=windows10,c11

#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

#define AppName (LPWSTR)L"C:\\Windows\\notepad.exe"

int main() {
    cout << "即将创建子进程notepad.exe" << endl;

    STARTUPINFO startupinfo; // 初始化信息
    PROCESS_INFORMATION processInformation; // 进程信息
    ZeroMemory(&startupinfo, sizeof(startupinfo)); // 初始化内存空间
    ZeroMemory(&processInformation, sizeof(processInformation)); // 初始化内存空间

    if (CreateProcess(AppName, nullptr, nullptr, nullptr, false, CREATE_NEW_CONSOLE, nullptr, nullptr, &startupinfo, &processInformation)) {
        cout << "创建进程成功" << endl;
    }
    else {
        cout << "创建进程失败" << endl;
        return -1;
    }

    cout << "按回车以关闭子进程" << endl;
    string temp;
    
    getline(cin, temp);

    // 关闭子进程的进程句柄和线程句柄
    TerminateThread(processInformation.hThread, 0);
    TerminateProcess(processInformation.hProcess, 0);
    

    cout << "子进程已结束" << endl;

    return 0;
}
