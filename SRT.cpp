#include "SRT.h"

SRT :: SRT(vector<Job> works)
{
    init_works(works);
}

bool SRT :: Cmp_arrive_time(Job a, Job b)
{
    return a.get_arrive_time() < b.get_arrive_time();
}

void SRT :: run()
{
    vector<Job> ready_queue = get_ready_queue();
    sort(ready_queue.begin(), ready_queue.end(), Cmp_arrive_time);

    int flag = 0;//记录已完成进程的个数
    int time = 0;//模拟计时器，每次循环+1
    int cur_ready_queue = -1;//当前进程下标，-1表示没有正在执行的进程
    bool ready[4] = {0};//ready[i]表示第i号进程的状态，0为没有就绪，1反之。
    vector<string> cons;//存储调度顺序，最后输出。
    while(flag != 4)
    {
        /* 处理当前进程状态 */
        if(cur_ready_queue != -1)
        {
            ready_queue[cur_ready_queue].used_time++;
            if(ready_queue[cur_ready_queue].used_time == ready_queue[cur_ready_queue].get_execute_time())
            {
                flag ++;
                cur_ready_queue = -1;
            }
        }

        /* 判断是否有程序准备好 */
        bool diaodu = false;
        for(int i = 0; i<ready_queue.size(); i++)
        {
            if(ready_queue[i].get_arrive_time() == time)
            {
                ready[i] = true;
            }
            if(ready[i])
                diaodu = true;
        }

        /* 如果调度程序要进行判断 */
        if(diaodu)
        {
            int min_left_time_p;
            for(int i = 0; i<ready_queue.size(); i++)
            {
                if(ready[i])
                {
                    min_left_time_p = i;
                    break;
                }
            }

            for(int i = min_left_time_p + 1; i<ready_queue.size(); i++)
            {
                if(ready[i])
                {
                    if(ready_queue[i].get_execute_time() - ready_queue[i].used_time < ready_queue[min_left_time_p].get_execute_time() - ready_queue[min_left_time_p].used_time)
                    {
                        min_left_time_p = i;
                    }
                }
            }

            /* 决定下一个调度的进程 */
            if(cur_ready_queue == -1)
            {
                cur_ready_queue = min_left_time_p;
            }
            else
            {
                if(ready_queue[cur_ready_queue].get_execute_time() - ready_queue[cur_ready_queue].used_time > ready_queue[min_left_time_p].get_execute_time() - ready_queue[min_left_time_p].used_time)
                {
                    ready[cur_ready_queue] = 1;
                    cur_ready_queue = min_left_time_p;
                }
            }
            ready[cur_ready_queue] = 0;

            /* 存储调度顺序 */
            if(cons.size())
            {
                if(cons[cons.size()-1] != ready_queue[cur_ready_queue].get_name())
                    cons.push_back(ready_queue[cur_ready_queue].get_name());
            }
            else
            {
                cons.push_back(ready_queue[cur_ready_queue].get_name());
            }
        }
        ++time;
    }

    cout << "SRT" << endl;
    for(int i = 0; i < ready_queue.size(); i++)
    {
        cout << "job name = " << ready_queue[i].get_name() << endl;
    }


}
