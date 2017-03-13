#include "lacksDMA.h"
#include <cstring>


lacksDMA::lacksDMA(const char * c, const char * l, int r) : baseDMA(l, r)
{
	strncpy_s(color, c, COL_LEN-1);
	color[COL_LEN] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs) : baseDMA(rs)
{
	strncpy_s(color, c, COL_LEN - 1);
	color[COL_LEN] = '\0';
}


std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
	// TODO: 在此处插入 return 语句
	os << (const baseDMA &) ls;				//	cast to use baseDMA friend
	os << "Color: " << ls.color << std::endl;
	return os;
}
