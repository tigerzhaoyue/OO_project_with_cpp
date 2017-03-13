//Brass.h --bank accont class
#pragma once
#include <string>
class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass();  //virtual destructed func  //IMPORTANT!!//
};
