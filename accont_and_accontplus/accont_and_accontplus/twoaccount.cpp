//compare two types of account
#include <iostream>
#include "Brass.h"
#include "BrassPlus.h"
int main()
{
	using std::cout;
	using std::endl;

	Brass wpx("Peixuan Wang", 381299, 4000.00);
	BrassPlus zy("Yue Zhao", 382288, 3000.00);
	wpx.ViewAcct();
	cout << endl;
	zy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 into the Yue Zhao Account:\n";
	zy.Deposit(1000.00);
	cout << "New balance: $" << zy.Balance() << endl;
	cout << "Withdraw $4200 from the wpx Account:\n";
	wpx.Withdraw(4200.00);
	cout << "wpx account balance: $" << wpx.Balance() << endl;
	cout << "Withdrawing $4200 from Yue Zhao account:\n";
	zy.Withdraw(4200.00);
	zy.ViewAcct();

	system("pause");
	return 0;
}