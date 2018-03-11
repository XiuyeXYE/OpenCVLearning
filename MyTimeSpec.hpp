

#ifndef __TIMESPEC_H_
#define __TIMESPEC_H_
#include<ctime>


class TimeSpec{
    private:
        static clock_t start;
        static clock_t end;
    private:
        static double cost_time();
    public:
        static void begin();
        static double to_end();
        static void print_cost_time();
};


clock_t TimeSpec::start = 0;
clock_t TimeSpec::end = 0;
void TimeSpec::begin(){
    start = clock();
}
double TimeSpec::to_end(){
    end = clock();
    return cost_time();
}
double TimeSpec::cost_time(){
    return double(end - start)/CLOCKS_PER_SEC;
}

void TimeSpec::print_cost_time(){
    println("From beginning to end totally costs: ",to_end()," s");
}

#endif

