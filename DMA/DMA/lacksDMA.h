#pragma once
#include "dma.h"
class lacksDMA :
	public baseDMA
{
private:
	enum{ COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
	lacksDMA(const char * c, const baseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const lacksDMA & ls);
};

