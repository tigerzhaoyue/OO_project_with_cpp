//Time.h Time class using operator overloading
#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddHr(int h);
	void AddMin(int m);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(double mult) const;
	friend Time operator*(double m, const Time & t)
		{return t * m;}//inline definition
	friend ostream & operator<<(ostream & os, const Time & t);
	void Show() const;
	~Time();
};

