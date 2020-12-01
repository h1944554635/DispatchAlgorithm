#include "program.h"
#include "Dispatcher.h"
#include "FCFS.h"
#include "FileReader.h"

Program::Program()
{
    dispatcher = NULL;
}

void Program::input()
{
    cout << "***********************************调度算法***********************************" << endl;
    cout << endl;
    cout << "*************作业调度*************      *************进程调度*****************" << endl;
    cout << "       1. FCFS(先来先服务)                  4. SPF(短进程优先-非抢占)" << endl;
    cout << "       2. SJF(短作业优先)                   5. SRT(最短剩余时间优先-抢占)" << endl;
    cout << "       3. HRRN(高响应比优先)                6. EDF(最早截止时间优先-非抢占)" << endl;
    cout << "                                            7. LLF(最低松弛度优先-抢占)" << endl;
    cout << "请输入要测试的调度算法序号: ";

    cin >> this->n;
}

void Program::init()
{
    /**
        //文件读取,存放在Job数组 works中
        this->works =
    */
    FileReader file_reader;
    works = file_reader.read_from_file("jobs.txt");

    //初始化对象
    this->dispatcher = NULL;

    switch(n)
    {
    case 1:
        dispatcher = new FCFS(works);

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    default:
        //非法输入
        break;

    }
}

void Program::run()
{
    //cout << dispatcher << endl;
    this->dispatcher->run();
}
