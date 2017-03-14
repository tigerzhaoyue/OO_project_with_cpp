#include "Student.h"

using std::ostream;
using std::endl;
using std::istream;
using std::string;

std::ostream & Student::arr_out(std::ostream & os) const
{
	// TODO: 在此处插入 return 语句
	int i;
	int lim = scores.size();
	if (lim > 0)
	{
		for (i = 0; i < lim; i++)
		{
			os << scores[i] << " ";	//use valarray<double> operator[]   AND  friend ostream & operator<<(ostream & os, const valarray & va)
			if (i % 5 == 4)
				os << endl;	//change line
		}
		if (i % 5 != 0)		//if == 0  endl  has outputed
			os << endl;
	}
	else
	{
		os << " empty array" << endl;
	}
	return os;	 //ensure  cout<<...<<...<<... many << ops
}

Student::Student() :name("NullName"), scores()   //have no info
{
	//initial in list after func   
	//do nothing here
}

Student::Student(const std::string & s) : name(s), scores()	// have name
{
}

Student::Student(int n) : name("NullNmae"), scores(n)		//have num of subjects
{
}

Student::Student(const std::string & s, int n) : scores(n)//have name and num of subjects
{
}

Student::Student(const std::string & s, const ArrayDb & a) : name(s) , scores(a)//have name and a already ArrayDb   (call ArrayDb copy func)
{
}

Student::Student(const char * str, const double * pd, int n) : name(str), scores(pd,n)	//call string::string(char * ch)  and ArrayDb::ArrayDb(double * array, int size)
{
}

double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else

		return 0.0;
}

const std::string & Student::Name() const
{
	// TODO: 在此处插入 return 语句
	return name;
}

double & Student::operator[](int i)
{
	// TODO: 在此处插入 return 语句
	return scores[i];		//	use valarray<double> ::operator[] here
}

double Student::operator[](int i) const
{
	return scores[i];		//	use valarray<double> ::operator[] here
}


Student::~Student()
{
	//do nothing
}

std::istream & operator>>(std::istream & is, Student & stu)
{
	// TODO: 在此处插入 return 语句
	is >> stu.name;			//	use friend istream & operator>>(istream & is , const string & s )
	return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
	// TODO: 在此处插入 return 语句
	getline(is, stu.name);	// use friend istream & getline(istream & is , const string & s)
	return is;
}

std::ostream & operator<<(std::ostream & os, Student & stu)
{
	// TODO: 在此处插入 return 语句
	os << "Scores for " << stu.name << ";\n";
	stu.arr_out(os);		//use private method to output stu info to os
	return os;
}
