#include "hasDMA.h"
#include <cstring>


hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	strcpy_s(style, std::strlen(s) + 1 ,s);
}

hasDMA::hasDMA(const char * s, const baseDMA & rs) : baseDMA(rs)
{
	style = new char[std::strlen(s) + 1];
	strcpy_s(style, std::strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA & hs) : baseDMA(hs)	//	invoke baseDMA constructor here first
{
	//copy other data then
	style = new char[std::strlen(hs.style) + 1];
	strcpy_s(style, std::strlen(hs.style) + 1, hs.style);
}

hasDMA::~hasDMA()
{
	//fisrt aotu invoke baseDMA destructor to release base data.

	//invoke ~baseDMA() here.
	//then  release hasDMA data:
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & rs)
{
	// TODO: 在此处插入 return 语句
	if (this == &rs)
		return *this;
	baseDMA::operator=(rs);
	/////////////////
	//NOTE HERE:
	//can't use    *this = rs     or we would go in a recursion (call hasDMA:operator=())
	/////////////////
	delete[] style;
	style = new char[std::strlen(rs.style) + 1];
	strcpy_s(style, std::strlen(rs.style) + 1, rs.style);
	return *this;

}

std::ostream & operator<<(std::ostream & os, const hasDMA & rs)
{
	// TODO: 在此处插入 return 语句
	os << (const baseDMA &)rs;
	os << "Style : " << rs.style << std::endl;
	return os;
}
