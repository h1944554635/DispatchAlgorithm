#include "FCFS.h"


FCFS::FCFS(vector<Job> works)
{
    init_works(works);
}

bool FCFS :: Cmp( Job a,  Job b)
{
    if(a.get_arrive_time()<b.get_arrive_time())
        return true;
    else
        return false;
}

void FCFS::sort_arrive_time(vector<Job> &ready_queue)
{

    sort(ready_queue.begin(), ready_queue.end(),Cmp);
    /*
    for(int i=0; i<ready_queue.size()-1; i++)
        for(int j=i+1; j<ready_queue.size(); j++)
        if(ready_queue[j].get_arrive_time() < ready_queue[i].get_arrive_time())
        {
            string na;
            int at,rt;

            na=ready_queue[i].get_name();
            ready_queue[i].set_name(ready_queue[j].get_name()) ;
            ready_queue[j].set_name(na);

             at=ready_queue[i].get_arrive_time();
            ready_queue[i].set_arrive_time(ready_queue[j].get_arrive_time());
             ready_queue[j].set_arrive_time(at);

            rt=ready_queue[i].get_execute_time();
            ready_queue[i].set_execute_time(ready_queue[j].get_execute_time());
             ready_queue[j].set_execute_time(rt);

        }
        */
}

void FCFS::run()
{
    vector<Job> ready_queue = get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(),Cmp);
   // sort_arrive_time(ready_queue);

    cout << "FCFS" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }
}
