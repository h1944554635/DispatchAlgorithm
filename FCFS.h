#ifndef FCFS_H_INCLUDED
#define FCFS_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"
#include <algorithm>

using namespace std;

class FCFS : public Dispatcher
{
private:

public:

    FCFS(vector<Job> works);


    void sort_arrive_time(vector<Job> &ready_queue);

    static bool Cmp( Job a,  Job b);

    void run();

};

#endif // FCFS_H_INCLUDED
