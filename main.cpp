#include <iostream>
#include "program.h"

using namespace std;

int main()
{
    Program program;
    //while(1)
    //{

        /**
         * program.input ��ӡ��ʾ������ȡ�û����룬
         * program.init ��ȡ�ļ�����ʼ������
         * program.run ִ�ж���
         */
         program.input();
         program.init();
         program.run();

    //}
    return 0;
}
