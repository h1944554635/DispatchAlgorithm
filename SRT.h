#ifndef SRT_H_INCLUDED
#define SRT_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"
#include <algorithm>
#include <vector>

using namespace std;

class SRT : public Dispatcher
{
public:
    int rest_time;

    SRT(vector<Job> works);

    static bool Cmp_arrive_time(Job a, Job b);

    void run();
};


#endif // SRT_H_INCLUDED
