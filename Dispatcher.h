#ifndef DISPATCHER_H_INCLUDED
#define DISPATCHER_H_INCLUDED
#include <vector>
#include "Job.h"

using namespace std;

class Dispatcher
{
private:

    vector<Job> ready_queue;//��ҵ��������

public:

    //Dispatcher(int n, vector<Job> works);//��ʼ��ѡ�еĵ����㷨����

    void init_works(vector<Job> works);

    void push_to_ready_queue(Job job);//��ֹͣ����ҵ�Żؾ�������

    vector<Job> get_ready_queue();

    virtual void run() = 0;


};

#endif // DISPATCHER_H_INCLUDED
