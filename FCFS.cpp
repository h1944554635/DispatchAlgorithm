#include "FCFS.h"

FCFS::FCFS(vector<Job> works)
{
    init_works(works);
}

void FCFS::run()
{
    vector<Job> ready_queue = get_ready_queue();
    cout << "FCFS" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }
}
