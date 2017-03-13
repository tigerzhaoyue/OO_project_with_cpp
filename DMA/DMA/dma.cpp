#include "dma.h"
#include <cstring>


baseDMA::baseDMA(const char * l, int r)
{
	label = new char[std::strlen(l) + 1];
	strcpy_s(label, std::strlen(l) + 1, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)				//deep copy func
{
	label = new char[std::strlen(rs.label) + 1];
	strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)		//	deep assign func
{
	// TODO: 在此处插入 return 语句
	if (this == &rs)
		return *this;

	delete[] label;			//release this->lable first
	label = new char[std::strlen(rs.label) + 1];
	strcpy_s(label, std::strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	//copy over
	return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)	//
{
	// TODO: 在此处插入 return 语句
	os << "Label1: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}
