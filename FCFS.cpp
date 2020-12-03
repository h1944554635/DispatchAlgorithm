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

void FCFS::run()
{
    vector<Job> ready_queue = get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(),Cmp);

    cout << "FCFS" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }
}
