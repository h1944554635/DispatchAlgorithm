#ifndef FILEWRITER_H_INCLUDED
#define FILEWRITER_H_INCLUDED
#include <string>
#include <fstream>

using namespace std;

class FileWriter
{
private:
    ofstream writer;

public:

    //void open_file(string filename);

    void write_to_file();
};


#endif // FILEWRITER_H_INCLUDED
