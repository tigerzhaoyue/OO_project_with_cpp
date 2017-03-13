//Customer is contained in queue
#pragma once
class Customer
{
private:
	long arrive;		//time of arrival
	int processstime;	//time for process
public:
	Customer() { arrive = processstime = 0; }

	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processstime; }
};

