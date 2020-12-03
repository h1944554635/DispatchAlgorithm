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
    int cycle;
    int deadline;
    float HRR;
    int priority;
    int start_time;

public:
    /*
    Job(string name, int execute_time);
    Job(string name, int execute_time,int arrive_time);
    Job(string name, int execute_time,int arrive_time,  int deadline);
    Job(string name, int execute_time,int arrive_time,  int deadline, int cycle);
    */
    int isfinished;
    int used_time;


    string get_name();

    void set_name(string name);

    int get_arrive_time();

    void set_arrive_time(int time);

    int get_execute_time();

    void set_execute_time(int time);

    int get_deadline();

    void set_deadline(int deadline);

    int get_cycle();

    void set_cycle(int cycle);

    int get_begin_time();

    void set_begin_time(int time);

    int get_finish_time();

    void set_finish_time(int time);

    int get_remain_time();

    void set_remain_time(int time);

    float get_HRR();

    void set_HRR(float HRR);

    int get_priority();

    void set_priority(int priority);

    int get_start_time();

    void set_start_time(int time);


};

#endif // JOB_H_INCLUDED
