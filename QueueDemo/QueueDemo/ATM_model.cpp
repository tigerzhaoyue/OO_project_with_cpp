#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);	//	is there a new customer

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	//setting things up
	std::srand(std::time(0));

	cout << "Case Study:Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);	//	line queue hols up to qs people

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	//simulation will run 1 cycle per min
	long cyclelimit = MIN_PER_HR*hours;

	cout << "Enter the average number of customers per hour: ";
	double perhour;
	cin >> perhour;
	double min_per_cust;	//average time between arrival
	min_per_cust = MIN_PER_HR/perhour;

	Item temp;					//new cuntomer
	long turnaways = 0;			//turned away by full queue
	long customers = 0;			//joined the queue
	long served = 0;			//served during the simulation
	long sum_line = 0;			//cumulative line length
	int wait_time = 0;			//time until autoteller is free
	long line_wait = 0;			//cumulative time in line


	//running the simulation:
	for(int cycle = 0 ; cycle < cyclelimit ; cycle++)
	{
		if (newcustomer(min_per_cust))	//is there comes a new customer?   
		{
			if (line.isfull())
				turnaways++;		//	leave 
			else
			{
				customers++;
				temp.set(cycle);	//	cycle = time of arrival, so.
				line.enqueue(temp);
			}
		}

		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeueu(temp);		//	attend next customer after that 
			wait_time = temp.ptime();	//after ptime(),machine will be free
			line_wait += cycle - temp.when();	//	temp is front of queue, calculate the time he waited. cycle is time now, temp.when() is his arrival
			served++;					//served number ++
		}

		if (wait_time > 0)
			wait_time--;				//a minute passed...

		sum_line += line.queuecount();
	}

	//report the result:
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << "	turnaways: " << turnaways << endl;
		cout << "average queue size:";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: " << (double)line_wait / served << " minutes" << endl;
	}
	else
		cout << "No customers!" << endl;
	cout << "Simulation done!" << endl;
	
	system("pause");
	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
	//X=AVERAGE TIME (set by user), IN MINUTES, BETWEEN CUSTOMERS
	//return value is true if customer shows up this minute
}
