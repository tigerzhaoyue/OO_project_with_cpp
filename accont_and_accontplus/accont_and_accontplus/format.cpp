//formatting stuff
#include <iostream>
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat()
{
	//set up ###.## format
	return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	std::cout.setf(f, std::ios_base::floatfield);
	std::cout.precision(p);
}