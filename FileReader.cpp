#include "FileReader.h"

vector<Job> FileReader::read_from_file(string filename)
{
    vector<Job> works;

    /**
    * 读取文件，将数据存入Job各个字段，未指定的则留空，将Job存入works数组
    */

    ifstream reader;
    reader.open(filename.c_str(), ios::in);

    string line;

    //char test[1024];
    getline(reader, line);
    vector<string> field_names = string_split(line, ',');

/*
    for(unsigned long long i = 0; i < field_names.size(); i++)
    {
        cout << field_names[i] << " ";
    }
    cout << endl;
*/

    while(!reader.eof())
    {
        getline(reader, line);
        //cout << "line=" << line << endl;
        //reader.getline(test, 1024);
        //cout << line << endl;
        vector<string> fields;
        if(line.compare("") != 0)
        {
            //cout << "line=" << line << endl;
            fields = string_split(line, ',');
        }
        else{
            break;
        }
        /*
        for(unsigned long long i = 0; i < field_names.size(); i++)
        {
            cout << field_names[i] << " ";
        }
        */
        cout << endl;
        /*
                for(unsigned long long i = 0; i < fields.size(); i++)
                {
                    cout << fields[i] << " ";
                }
                cout << endl;
        */;

        works.push_back(init_job(field_names, fields));
    }


    reader.close();
/*
    for(int i = 0; i < works.size(); i++)
    {
        cout << works[i].get_name() << endl;
        cout << works[i].get_arrive_time() << endl;
        cout << works[i].get_execute_time() << endl;
    }
*/

    return works;
}

vector<string> FileReader::string_split(string str, char delim)
{

    vector<string> v;
    while(str.find_first_of(delim) != string::npos)
    {
        v.push_back(str.substr(0,str.find_first_of(delim)));
        str = str.substr(str.find_first_of(delim) + 1);
        //cout << str << endl;
    }
    v.push_back(str);
    return v;
}

Job FileReader::init_job(vector<string> field_names, vector<string> fields)
{
    /*
    for(unsigned long long i = 0; i < fields.size(); i++)
    {
        cout << field_names[i] << " ";
    }
    */
    //cout << endl;

    /*
    Job* job;
    if(type == 2)
    {
        job = new Job(fields[0], stoi(fields[1]));
    }
    else if(type == 3)
    {
        job = new Job(fields[0], stoi(fields[1]), stoi(fields[2]));
    }
    else if(type == 4)
    {
        job = new Job(fields[0], stoi(fields[1]), stoi(fields[2]), stoi(fields[3]));
    }
    else if(type == 5)
    {
        job = new Job(fields[0], stoi(fields[1]), stoi(fields[2]), stoi(fields[3]), stoi(fields[4]));
    }
    */
    Job job;
    for(unsigned long long i = 0; i < field_names.size(); i++)
    {
        //cout << i << endl;

        //cout << "init:  field_name=" << field_names[i] << "  field=" << fields[i] << endl;
        //cout << field_names[i] << endl;
        //cout << fields[i] << endl;
        //cout << endl;
        try
        {

            if(field_names[i].compare("job_name") == 0)
            {
                //cout << "set name" << endl;
                job.set_name(fields[i]);
            }
            else if(field_names[i].compare("arrive_time") == 0)
            {
                //cout << "set arrive time" << endl;
                job.set_arrive_time(stoi(fields[i]));
            }
            else if(field_names[i].compare("execute_time") == 0)
            {
                //cout << "set execute time" << endl;
                job.set_execute_time(stoi(fields[i]));
            }
            else if(field_names[i].compare("deadline") == 0)
            {
                //cout << "set deadline" << endl;
                job.set_deadline(stoi(fields[i]));
            }
            else if(field_names[i].compare("cycle") == 0)
            {
                //cout << "set cycle" << endl;
                job.set_cycle(stoi(fields[i]));
            }
        }
        catch(...)
        {
            cout << "convert faild" << endl;
            exit(0);
        }
    }
    return job;
}
