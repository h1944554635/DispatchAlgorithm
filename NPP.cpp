#include "NPP.h"

NPP :: NPP(vector<Job> works)
{
    init_works(works);
}

bool NPP :: Cmp_arrive_time( Job a,  Job b)
{
   return a.get_arrive_time() < b.get_arrive_time();
}

bool NPP :: Cmp_priority(Job a, Job b)
{
    return a.get_priority() > b.get_priority();
}

void NPP :: run()
{
    vector<Job> ready_queue = get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(), Cmp_arrive_time); //第一个到达的先执行

    ready_queue[0].set_finish_time( ready_queue[0].get_arrive_time() + ready_queue[0].get_execute_time() );

    int now_time = ready_queue[0].get_finish_time();
    int k=1;
    for(int i=1; i<ready_queue.size(); )
    {
        while(i < ready_queue.size() && ready_queue[i].get_arrive_time() <= now_time )
        {
           // ready_queue[i].set_finish_time() = ready_queue[i-1].get_finish_time() + ready_queue[i].get_execute_time();
            i++;
        }
        sort(ready_queue.begin() + k, ready_queue.begin() + i, Cmp_priority); //剩下的按照优先级顺序执行
        k=i;
    }



    cout << "非抢占式优先级" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }
}
