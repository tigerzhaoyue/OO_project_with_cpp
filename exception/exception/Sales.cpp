#include "Sales.h"
using std::string;

Sales::bad_index::bad_index(int ix, const std::string & s) : std::logic_error(s), bi(ix)    
{
	//s will initial logic_error::what()
}

Sales::Sales(int yy)
{
	year = yy;
	for (int i = 0; i < MONTHS; ++i)
		gross[i] = 0;
}

Sales::Sales(int yy, const double * gr, int n)
{
	year = yy;
	int lim = (n < MONTHS) ? n : MONTHS;
	int i;
	for (i = 0; i < lim; ++i)
		gross[i] = gr[i];
	for (; i < MONTHS; ++i)		//fill the left gross  0
		gross[i] = 0;
}

double Sales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}

double & Sales::operator[](int i)  
{
	if (i < 0 || i >= MONTHS)
		throw bad_index(i);
	return gross[i];
}






///////////////////////////////////////////LabelSales ////////////////////////////////////////////////////////////////////////






LabeledSales::nbad_index::nbad_index(const std::string & lb, int ix, const std::string & s) : Sales::bad_index(ix,s)
{
	lbl = lb;			//using string & operator=(string & s)
}

LabeledSales::LabeledSales(const std::string & lb, int yy) : Sales(yy)
{
	label = lb;			//using string & operator=(string & s)
}

LabeledSales::LabeledSales(const std::string & lb, int yy, const double * gr, int n) : Sales(yy, gr, n)
{
	label = lb;			//using string & operator=(string & s)
}

double LabeledSales::operator[](int i) const
{
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(),i);
	return Sales::operator[](i);		//using father class operator[] to access private gross[]    
	//return gross[i];					if gross is protected  it's also ok 
}

double & LabeledSales::operator[](int i)
{
	if (i < 0 || i >= MONTHS)
		throw nbad_index(Label(), i);
	return Sales::operator[](i);
	return gross[i];
}
