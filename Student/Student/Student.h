//Student.h -- practice has-a model. using containment
#pragma once
#include <iostream>
#include <string>
#include <valarray>
class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;	//contained obj
	ArrayDb scores;		//contained obj

	//some private obJ:
	std::ostream & arr_out(std::ostream & os) const;

public:
	Student();
	explicit Student(const std::string & s);
	explicit Student(int n);
	Student(const std::string & s, int n);
	Student(const std::string & s, const ArrayDb & a);
	Student(const char * str, const double * pd, int n);
	double Average() const;
	const std::string & Name() const;
	double & operator[](int i);
	double operator[](int i) const;	//	const is must. or can't overload only differ by return type!
	~Student();
	
//friends of IO:
	//input
	friend std::istream & operator>>(std::istream & is, Student & stu);	//1 word
	friend std::istream & getline(std::istream & is, Student & stu);	//1 line
	//output
	friend std::ostream & operator<<(std::ostream & os, Student & stu);	//overload << op for cout
};

