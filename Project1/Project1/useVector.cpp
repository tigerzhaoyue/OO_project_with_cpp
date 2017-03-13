//随机漫步问题  一个人走到离原点50的位置需要多少步？ rand()
#include <iostream>
#include "Vector.h"
#include <ctime>
#include <cstdlib>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance :";
	while(cin>>target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		while(result.magval()<target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject has th following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance :";

	}
	cout << "Bye~" << endl;
	cin.clear();
	system("pause");
	return 0;
}