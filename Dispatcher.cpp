#include "Dispatcher.h"
#include "FCFS.h"


void Dispatcher::init_works(vector<Job> works)
{
    this->ready_queue = works;
}

void Dispatcher::push_to_ready_queue(Job job)
{
    ready_queue.push_back(job);
}

void Dispatcher::run(){}
