#ifndef DISPATCHER_H_INCLUDED
#define DISPATCHER_H_INCLUDED
#include <vector>
#include "Job.h"

using namespace std;

class Dispatcher
{
private:

    vector<Job> ready_queue;//作业就绪队列

public:

    //Dispatcher(int n, vector<Job> works);//初始化选中的调度算法对象

    void init_works(vector<Job> works);

    void push_to_ready_queue(Job job);//将停止的作业放回就绪队列

    vector<Job> get_ready_queue();

    virtual void run() = 0;


};

#endif // DISPATCHER_H_INCLUDED
