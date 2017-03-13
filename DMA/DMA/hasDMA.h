#pragma once
#include "dma.h"
class hasDMA :
	public baseDMA
{
private:
	char * style;

public:
	hasDMA(const char * s = "none", const char* l = "null", int r = 0);
	hasDMA(const char * s, const baseDMA & rs);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

