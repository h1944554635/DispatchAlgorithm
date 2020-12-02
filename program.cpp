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
    cout << "***********************************�����㷨***********************************" << endl;
    cout << endl;

    //cout << "*************��ҵ����*************      *************���̵���*****************" << endl;
    cout << "       1. FCFS(�����ȷ���)                  6. SPF(�̽�������-����ռ)" << endl;
    cout << "       2. SJF(����ҵ����)                   7. SRT(���ʣ��ʱ������-��ռ)" << endl;
    cout << "       3. HRRN(����Ӧ������)                8. RR-4(ʱ��Ƭ��ת����)" << endl;
    cout << "       4. ����ռʽ���ȼ�                    9. EDF(�����ֹʱ������-����ռ)" << endl;
    cout << "       5. ��ռʽ���ȼ�                      10. LLF(����ɳڶ�����-��ռ)" << endl;
    cout << "      *********                 11. ���м��㷨                  ***********" << endl;
    cout << endl;
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
    string filename;
    cout << "������Ҫ��ȡ���ļ���: ";
    cin >> filename;
    works = file_reader.read_from_file(filename.c_str());

    //��ʼ������
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
        //�Ƿ�����
        break;

    }
}

void Program::run()
{
    //cout << dispatcher << endl;
    this->dispatcher->run();
}
