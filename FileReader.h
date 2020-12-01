#ifndef FILEREADER_H_INCLUDED
#define FILEREADER_H_INCLUDED
#include <vector>
#include <fstream>
#include "Job.h"

using namespace std;

class FileReader
{
private:

public:

    vector<Job> read_from_file(string filename);

    vector<string> string_split(string str, char delim);

    Job init_job(vector<string> field_names, vector<string> fields);

};

#endif // FILEREADER_H_INCLUDED
