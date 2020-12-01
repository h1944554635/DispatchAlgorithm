#include <iostream>
#include "program.h"

using namespace std;

int main()
{
    Program program;
    //while(1)
    //{

        /**
         * program.input 打印提示符，读取用户输入，
         * program.init 读取文件，初始化对象
         * program.run 执行对象
         */
         program.input();
         program.init();
         program.run();

    //}
    return 0;
}
