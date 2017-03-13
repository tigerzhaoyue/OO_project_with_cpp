#pragma once
#include "Brass.h"
class BrassPlus :
	public Brass
{
private:
	double maxLoan;
	double rate;
	double oweBank;

public:
	BrassPlus(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double m);
	void ResetRate(double r);
	void ResetOwes();
};
