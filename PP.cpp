#include "PP.h"

PP :: PP(vector<Job> works)
{
    init_works(works);
}

bool PP :: Cmp_arrive_time( Job a,  Job b)
{
   return a.get_arrive_time() < b.get_arrive_time();
}

bool PP :: Cmp_priority(Job a, Job b)
{
    return a.get_priority() > b.get_priority();
}

void PP :: run()
{
    vector<Job> ready_queue=get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(), Cmp_arrive_time);
    for(int i=0; i<ready_queue.size(); i++)
    {

    }

}
