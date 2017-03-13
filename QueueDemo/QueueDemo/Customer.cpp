#include "Customer.h"
#include <cstdlib>	//	for rand()

void Customer::set(long when)
{
	processstime = std::rand() % 3 + 1;
	arrive = when;
}