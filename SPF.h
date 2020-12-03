#ifndef SPF_H_INCLUDED
#define SPF_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"
#include <algorithm>

using namespace std;

class SPF : public Dispatcher
{
public:
    SPF(vector<Job> works);

    static bool Cmp_arrive_time(Job a, Job b);

    static bool Cmp_start_time(Job a, Job b);

    void run();

};


#endif // SPF_H_INCLUDED
