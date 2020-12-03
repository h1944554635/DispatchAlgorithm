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

    int flag = 0;//��¼����ɽ��̵ĸ���
    int time = 0;//ģ���ʱ����ÿ��ѭ��+1
    int cur_ready_queue = -1;//��ǰ�����±꣬-1��ʾû������ִ�еĽ���
    bool ready[4] = {0};//ready[i]��ʾ��i�Ž��̵�״̬��0Ϊû�о�����1��֮��
    vector<string> cons;//�洢����˳����������
    while(flag != 4)
    {
        /* ����ǰ����״̬ */
        if(cur_ready_queue != -1)
        {
            ready_queue[cur_ready_queue].used_time++;
            if(ready_queue[cur_ready_queue].used_time == ready_queue[cur_ready_queue].get_execute_time())
            {
                flag ++;
                cur_ready_queue = -1;
            }
        }

        /* �ж��Ƿ��г���׼���� */
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

        /* ������ȳ���Ҫ�����ж� */
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

            /* ������һ�����ȵĽ��� */
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

            /* �洢����˳�� */
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
