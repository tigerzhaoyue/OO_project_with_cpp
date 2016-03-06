#include <iostream>
#include "Time.h"
using namespace std;

int main()
{
    Time t1;
    Time t2(0, 12, 13);
    Time t3(12, 13,12);
    t1.setHour(24);
    t1.setMinute(66);
    t1.setSecond(58);
    t1.printUniversal();
    cout<<"\n";
    t2.printStandard();
    cout<<"\n";
    t3.printStandard();
    cout<<"\n";
    return 0;
}
