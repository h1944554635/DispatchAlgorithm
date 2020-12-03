#ifndef PP_H_INCLUDED
#define PP_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"
#include <algorithm>

using namespace std;

class PP : public Dispatcher
{
public :
    PP(vector<Job> works);

    static bool Cmp_arrive_time(Job a, Job b);

    static bool Cmp_priority(Job a, Job b);

    void run();
};


#endif // PP_H_INCLUDED
