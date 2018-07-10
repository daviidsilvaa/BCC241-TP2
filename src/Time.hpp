
#ifndef TIME_HPP
#define TIME_HPP

#include <time.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Time{
public:
    duration<double> time_span2;
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;

    Time(){ }

    ~Time(){ }

    void getInit(){
        this->t1 = high_resolution_clock::now();
    }

    void getFinish(){
        t2 = high_resolution_clock::now();
    }

    double getTotalTime(){
        this->time_span2 = duration_cast<duration<double>>(t2-t1);
        return (double)(this->time_span2.count());
    }

    void mountFile(char *path){
        ofstream time_outfile;

        time_outfile.open("tempo/tempo.csv", time_outfile.app);

        time_outfile << path << ";" << this->getTotalTime() << endl;

        time_outfile.close();
    }

};

#endif
