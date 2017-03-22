#ifndef __TIME_H__
#define __TIME_H__

#include <iostream>
using namespace std;

class Time
{
public:
    void setTime(int, int, int);
    void showTime(void);

private:
    int hour;
    int min;
    int sec;
};



#endif /*__TIME_H__*/
