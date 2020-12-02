#include "SJF.h"
#include <algorithm>

SJF :: SJF(vector<Job> works)
{
    init_works(works);
}

bool SJF :: Cmp(Job &a, Job &b)
{
    return a.get_execute_time()<b.get_execute_time();
}

void SJF :: run()
{
    vector<Job> ready_queue = get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(),Cmp);

    cout << "SJF" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }
}
