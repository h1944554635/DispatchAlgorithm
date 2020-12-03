#ifndef NPP_H_INCLUDED
#define NPP_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"
#include <algorithm>

using namespace std;

class NPP : public Dispatcher
{
public:
    NPP(vector<Job> works);

    static bool Cmp_arrive_time(Job a, Job b);

    static bool Cmp_priority(Job a, Job b);

    void run();

};


#endif // NPP_H_INCLUDED
