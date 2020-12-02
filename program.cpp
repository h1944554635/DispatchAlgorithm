#include "program.h"
#include "Dispatcher.h"
#include "FCFS.h"
#include "SJF.h"
#include "HRRN.h"
#include "FileReader.h"

Program::Program()
{
    dispatcher = NULL;
}

void Program::input()
{
    cout << "***********************************调度算法***********************************" << endl;
    cout << endl;

    //cout << "*************作业调度*************      *************进程调度*****************" << endl;
    cout << "       1. FCFS(先来先服务)                  6. SPF(短进程优先-非抢占)" << endl;
    cout << "       2. SJF(短作业优先)                   7. SRT(最短剩余时间优先-抢占)" << endl;
    cout << "       3. HRRN(高响应比优先)                8. RR-4(时间片轮转调度)" << endl;
    cout << "       4. 非抢占式优先级                    9. EDF(最早截止时间优先-非抢占)" << endl;
    cout << "       5. 抢占式优先级                      10. LLF(最低松弛度优先-抢占)" << endl;
    cout << "      *********                 11. 银行家算法                  ***********" << endl;
    cout << endl;
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
    string filename;
    cout << "请输入要读取的文件名: ";
    cin >> filename;
    works = file_reader.read_from_file(filename.c_str());

    //初始化对象
    this->dispatcher = NULL;

    switch(n)
    {
    case 1:
        dispatcher = new FCFS(works);

        break;
    case 2:
        dispatcher = new SJF(works);

        break;
    case 3:
        dispatcher = new HRRN(works);

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
