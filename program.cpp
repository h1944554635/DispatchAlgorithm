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
    cout << "***********************************�����㷨***********************************" << endl;
    cout << endl;
    cout << "*************��ҵ����*************      *************���̵���*****************" << endl;
    cout << "       1. FCFS(�����ȷ���)                  4. SPF(�̽�������-����ռ)" << endl;
    cout << "       2. SJF(����ҵ����)                   5. SRT(���ʣ��ʱ������-��ռ)" << endl;
    cout << "       3. HRRN(����Ӧ������)                6. EDF(�����ֹʱ������-����ռ)" << endl;
    cout << "                                            7. LLF(����ɳڶ�����-��ռ)" << endl;
    cout << "������Ҫ���Եĵ����㷨���: ";

    cin >> this->n;
}

void Program::init()
{
    /**
        //�ļ���ȡ,�����Job���� works��
        this->works =
    */
    FileReader file_reader;
    works = file_reader.read_from_file("jobs.txt");

    //��ʼ������
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
        //�Ƿ�����
        break;

    }
}

void Program::run()
{
    //cout << dispatcher << endl;
    this->dispatcher->run();
}
