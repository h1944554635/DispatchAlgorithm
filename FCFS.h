#ifndef FCFS_H_INCLUDED
#define FCFS_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"
#include <algorithm>
#include <functional>

using namespace std;

class FCFS : public Dispatcher
{
private:

public:

    FCFS(vector<Job> works);

    void run();

    static bool Cmp( Job a,  Job b);

    void sort_arrive_time(vector<Job> &ready_queue);

};

#endif // FCFS_H_INCLUDED
