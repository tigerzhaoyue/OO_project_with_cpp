#include "Time.h"
#include <iostream>
#include <iomanip>
using namespace std;
Time::Time()
{
    hour = minute = second = 0;
}

Time::Time(int hr, int min, int sec)
{
    setTime(hr, min, sec);
}

int Time::getHour()
{
    return hour;
}
int Time::getMinute()
{
    return minute;
}
int Time::getSecond()
{
    return second;
}

void Time::setTime(int hr, int min, int sec)
{
    setHour(hr);
    setMinute(min);
    setSecond(sec);
}
void Time::setHour(int hr)
{
    hour = (hr >=0 && hr< 24 )? hr:0;
}
void Time::setMinute(int min)
{
    minute = (min >=0 && min< 60 )? min:0;
}
void Time::setSecond(int sec)
{
    second = (sec >=0 && sec< 60 )? sec:0;
}

void Time::printUniversal()
{
    cout<<setfill('0')
        <<setw(2) << hour <<":"
        <<setw(2) << minute <<":"
        <<setw(2) << second;
}
void Time::printStandard()
{
    cout<<( (hour==12 )? 12:hour%12) <<":"
    <<setfill('0')
    <<setw(2)<<minute<<":"
    <<setw(2)<<second<<( (hour<12) ?"AM" : "PM");
}
