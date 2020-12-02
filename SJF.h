#ifndef SJF_H_INCLUDED
#define SJF_H_INCLUDED
#include "Dispatcher.h"
#include "Job.h"

class SJF : public Dispatcher
{
public:
     SJF(vector<Job> works);

    static bool Cmp( Job &a,  Job &b);

    void run();
};


#endif // SJF_H_INCLUDED
