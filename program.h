#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED
#include "Job.h"
#include "Dispatcher.h"

class Program
{
private:
    int n;
    Dispatcher* dispatcher;
    vector<Job> works;

public:

    Program();

    void input();

    void init();

    void run();

};

#endif // PROGRAM_H_INCLUDED
