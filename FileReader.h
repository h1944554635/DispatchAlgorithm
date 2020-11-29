#ifndef FILEREADER_H_INCLUDED
#define FILEREADER_H_INCLUDED
#include <vector>
#include "Job.h"

using namespace std;

class FileReader
{
private:

public:

    vector<Job> read_from_file(string filename);

};

#endif // FILEREADER_H_INCLUDED
