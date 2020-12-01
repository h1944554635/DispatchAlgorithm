#include "Job.h"

/*
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

Job::Job(string name, int execute_time,int arrive_time,  int deadline, int cycle)
{
    this->name = name;
    this->execute_time = execute_time;
    this->arrive_time = arrive_time;
    this->deadline = deadline;
    this->cycle = cycle;
}
*/


void Job::set_name(string name)
{
    this->name = name;
}

string Job::get_name()
{
    return name;
}

int Job::get_arrive_time()
{
    return arrive_time;
}

void Job::set_arraive_time(int time)
{
    this->arrive_time = time;
}

int Job::get_begin_time()
{
    return begin_time;
}

void Job::set_begin_time(int time)
{
    this->begin_time = time;
}

int Job::get_finish_time()
{
    return finish_time;
}

int Job::get_execute_time()
{
    return execute_time;
}

void Job::set_execute_time(int time)
{
    this->execute_time = time;
}

void Job::set_finish_time(int time)
{
    this->finish_time = time;
}

int Job::get_remain_time()
{
    return remain_time;
}

void Job::set_remain_time(int time)
{
    this->remain_time = time;
}

int Job::get_cycle()
{
    return cycle;
}

void Job::set_cycle(int cycle)
{
    this->cycle = cycle;
}

int Job::get_deadline()
{
    return deadline;
}

void Job::set_deadline(int deadline)
{
    this->deadline = deadline;
}
