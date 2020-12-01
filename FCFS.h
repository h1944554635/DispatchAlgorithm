#ifndef FCFS_H_INCLUDED
#define FCFS_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"

class FCFS : public Dispatcher
{
private:

public:

    FCFS(vector<Job> works);

    void run();

};

#endif // FCFS_H_INCLUDED
