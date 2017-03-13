#include "BrassPlus.h"
#include <iostream>
#include "format.h"
using std::cout;
using std::string;
using std::endl;

BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r) : Brass(s, an, bal)
{
	maxLoan = ml;
	oweBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r) : Brass(ba)
{
	maxLoan = ml;
	oweBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct() const
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "Maximum load: $" << maxLoan << endl;
	cout << "Owe to bank: $" << oweBank << endl;
	cout.precision(3);	//###.### format
	cout << "Loan Rate: " << 100 * rate << "%\n";
	restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt)
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - oweBank)
	{
		double advance = amt - bal;
		oweBank += advance*(1.0 + rate);
		cout << "Bank advace: $" << advance << endl;
		cout << "Finance charge: $" << advance*rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded! Transaction cancelled!\n";
	restore(initialState, prec);
}

void BrassPlus::ResetMax(double m)
{
	maxLoan = m;
}

void BrassPlus::ResetRate(double r)
{
	rate = r;
}

void BrassPlus::ResetOwes()
{
	oweBank = 0;
}
