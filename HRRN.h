#ifndef HRRN_H_INCLUDED
#define HRRN_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"

class HRRN : public Dispatcher
{
private:
    int HRR;
public:
    HRRN(vector<Job> works);

    static bool Cmp_arrive_time( Job &a,  Job &b);

    static bool Cmp_HRRN(Job &a, Job &b);

    void Compute_HRRN(vector<Job> &works, int i);

    void run();
};
#endif // HRRN_H_INCLUDED
