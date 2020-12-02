#include "HRRN.h"
#include <algorithm>

HRRN :: HRRN(vector<Job> works)
{
    init_works(works);
}

bool HRRN :: Cmp_arrive_time( Job &a,  Job &b)
{
   return a.get_arrive_time()<b.get_arrive_time();
}

bool HRRN :: Cmp_HRRN(Job &a, Job &b)
{
    return a.get_HRR()>b.get_HRR();
}

void HRRN :: Compute_HRRN(vector<Job> &ready_queue, int i)
{
    for(int j=i; j<ready_queue.size(); j++)
    {
        float wait_time = ready_queue[i-1].get_finish_time() - ready_queue[j].get_arrive_time();
        //cout<<ready_queue[j].get_name()<<"wait time is: "<<wait_time<<endl;
        ready_queue[j].set_HRR( wait_time*1.0/(float)ready_queue[j].get_execute_time()  ) ;
    }
}

void HRRN :: run()
{
    vector<Job> ready_queue = get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(),Cmp_arrive_time);   //先按到达时间排序

    ready_queue[0].set_finish_time( ready_queue[0].get_arrive_time() + ready_queue[0].get_execute_time() );

    for(int i = 1; i < ready_queue.size(); i++)
    {
        Compute_HRRN(ready_queue, i);
        sort(ready_queue.begin()+i, ready_queue.end(), Cmp_HRRN);
        ready_queue[i].set_finish_time( ready_queue[i-1].get_finish_time() + ready_queue[i].get_execute_time() );
        //cout<<ready_queue[i].get_name()<<" finish time is: "<<ready_queue[i].get_finish_time()<<endl;
    }

    cout << "HRRN" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }
}
