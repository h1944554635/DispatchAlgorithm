#include "SPF.h"

SPF :: SPF(vector<Job> works)
{
    init_works(works);
}

bool SPF :: Cmp_arrive_time(Job a, Job b)
{
    if(a.get_arrive_time() == b.get_arrive_time())
        return a.get_execute_time() < b.get_execute_time();

    return a.get_arrive_time() < b.get_arrive_time();
}

bool SPF :: Cmp_start_time(Job a, Job b)
{
    return a.get_start_time() < b.get_start_time();
}

void SPF :: run()
{
    vector<Job> ready_queue = get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(), Cmp_arrive_time);

    int finish_progress=0;
    int now_time=0;
    int i=0;
    while(finish_progress < ready_queue.size())
    {
        if(now_time > ready_queue[0].get_arrive_time() && finish_progress == 0)
        {
            now_time = ready_queue[0].get_arrive_time();
            ready_queue[0].set_start_time( ready_queue[0].get_arrive_time() );
            ready_queue[0].set_finish_time( now_time + ready_queue[0].get_execute_time() );
            ready_queue[0].isfinished=1;
            finish_progress++;
        }
        else if(now_time > ready_queue[i].get_arrive_time() && finish_progress>0)
        {
                int num=0;
                int temp;
                for(int j=0; j<ready_queue.size(); j++)
                {
                    if(ready_queue[j].isfinished == 1)
                        continue;
                    if( now_time >= ready_queue[j].get_arrive_time())
                    {
                        num++;
                        temp=j;
                    }
                }

                if(num==1)
                {
                    ready_queue[temp].set_start_time(now_time) ;
                    ready_queue[temp].set_finish_time(now_time + ready_queue[temp].get_execute_time());
                    ready_queue[temp].isfinished=1;
                    finish_progress++;
                    i++;
                }
                else if(num>1)
                {
                    int minProcess=0;
                    int k;
                    for(k=0; k<ready_queue.size(); k++)
                    {
                        if(ready_queue[k].isfinished==1)
                            continue;
                        else
                        {
                            if(ready_queue[k].get_execute_time() < ready_queue[minProcess].get_execute_time())
                                minProcess = k;
                        }
                    }
                    ready_queue[minProcess].set_start_time(now_time);
                    ready_queue[minProcess].set_finish_time(now_time +  ready_queue[minProcess].get_execute_time());
                    now_time =  ready_queue[minProcess].get_finish_time();
                    ready_queue[minProcess].isfinished = 1;
                    finish_progress++;
                }
        }
        else
            now_time++;
    }

    sort(ready_queue.begin(), ready_queue.end(), Cmp_start_time);

    cout << "SPF" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }

}
