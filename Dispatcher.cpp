#include "Dispatcher.h"
#include "FCFS.h"
#include "SJF.h"
#include "HRRN.h"
#include "NPP.h"
#include "SPF.h"
#include "SRT.h"


void Dispatcher::init_works(vector<Job> works)
{
    this->ready_queue = works;
}

void Dispatcher::push_to_ready_queue(Job job)
{
    ready_queue.push_back(job);
}

void Dispatcher::run(){}

vector<Job> Dispatcher::get_ready_queue()
{
    return ready_queue;
}
