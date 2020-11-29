#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

class Job
{
private:
    string name;
    int arrive_time;
    int begin_time;
    int execute_time;
    int remain_time;
    int finish_time;
    int deadline;

public:
    Job(string name, int execute_time);
    Job(string name, int execute_time, int arrive_time);
    Job(string name, int execute_time,int arrive_time,  int deadline);

    string get_name();

    void set_begin_time(int time);

    void set_finish_time(int time);
};

#endif // JOB_H_INCLUDED
