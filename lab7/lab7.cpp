#include <windows.h>
#include <string>
#include <iostream>
#include "ITask.h"
#include "Task.h"
#include "IWorker.h"

CRITICAL_SECTION CriticalSection;

int main(int argc, char* argv[])
{
    HANDLE hProcess = GetCurrentProcess();
    SetProcessAffinityMask(hProcess, 4);
    IWorker worker;
    const int number = 15;
    ITask* task[number];
    for (int i = 0; i < number; i++)
    {
        task[i] = new Task(i);
        Sleep(0.01);
        worker.ExecuteTask(task[i]);
    }

    return 0;
}