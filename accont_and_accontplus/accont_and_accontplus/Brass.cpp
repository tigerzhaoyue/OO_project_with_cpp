#include "Brass.h"
#include <iostream>
#include "format.h"
using std::cout;
using std::string;
using std::endl;

Brass::Brass(const std::string & s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed; " << "deposit is cancelled.\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
		cout << "Withdrawal amont must be positive!\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawal canceled." << endl;
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	//set ip ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client: " << fullName << endl;
	cout << "Account Number: " << acctNum << endl;
	cout << "Balance: $" << balance << endl;
	restore(initialState, prec);//restore original format
}

Brass::~Brass()
{
	//do nothing
}