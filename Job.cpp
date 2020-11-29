#include "Job.h"

Job::Job(string name, int execute_time)
{
    this->name = name;
    this->execute_time = execute_time;
}

Job::Job(string name, int execute_time, int arrive_time)
{
    this->name = name;
    this->execute_time = execute_time;
    this->arrive_time = arrive_time;
}

Job::Job(string name, int execute_time, int arrive_time, int deadline)
{
    this->name = name;
    this->execute_time = execute_time;
    this->arrive_time = arrive_time;
    this->deadline = deadline;
}


string Job::get_name()
{
    return name;
}

void Job::set_begin_time(int time)
{
    this->begin_time = time;
}

void Job::set_finish_time(int time)
{
    this->finish_time = time;
}
