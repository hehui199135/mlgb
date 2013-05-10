#include <iostream>
#include "QueryProcessor.h"
#include <boost/date_time/posix_time/posix_time.hpp>






using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string path="/home/daniel/Desktop/C++/Assignment/data/data";
    cout << "Welcome to the IR system by qsz13!"<< endl;
    cout << "Please type in the path(left blank for debug mode):" << endl;
    string p;
    getline(cin,p);
    if(p != "")
    {
        path = p;
    }


    boost::posix_time::ptime time1,time_now;
    boost::posix_time::millisec_posix_time_system_config::time_duration_type time_elapse;
    time1 = boost::posix_time::microsec_clock::universal_time();


    QueryProcessor c(path);



    time_now = boost::posix_time::microsec_clock::universal_time();
    time_elapse = time_now - time1;
    long milliseconds = time_elapse.total_milliseconds();
    cout<<"time_elapse :"<<milliseconds<<"ms"<<endl;




    bool flag = 1;
     while(flag)
     {
         flag = c.searchQuery();
         //c.getResult();
     }
    cout << "!";


    return 0;
}
