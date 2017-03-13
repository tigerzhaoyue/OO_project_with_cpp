//dma.h -- inheritance and dynamic memory allocation practice
#pragma once
#include <iostream>

//Base class using DMA
class baseDMA
{
private:
	char * label;
	int rating;

public:
	baseDMA(const char * l = "null", int r = 0);
	baseDMA(const baseDMA & rs);
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);

};

