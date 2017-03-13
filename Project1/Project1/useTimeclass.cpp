//useTimeclass.cpp -- using the Time class to learn operator overloading
#include <iostream>
#include "time.h"

int main()
{
	using std::cout;
	using std::endl;
	Time plannnig;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;
	cout << "Planning time =";
	plannnig.Show();
	cout << endl;

	cout << "coding time =";
	coding.Show();
	cout << endl;

	cout << "fixing time =";
	fixing.Show();
	cout << endl;

	total = coding + fixing;			//operator notation
	cout << "coding + fixing = ";
	total.Show();
	cout << endl;

	Time morefixing(3,28);
	cout << "more fixing time =";
	morefixing.Show();
	cout << endl;

	total = morefixing.operator+(total);	//function notation
	
	cout << "morefixing.operator+(total)=";
	total.Show();
	cout << endl;

	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;
	cout << "Aida and Tosca:\n" << endl;
	cout << aida << ";" << tosca << endl;	//friend func :	operaotr<< overload
	temp = aida + tosca;//operator+ overload
	cout << "Aida+Tosca: " << temp << endl;
	temp = aida * 1.17;		//member operator*
	cout << "Aida*1.17: " << temp << endl;
	cout << "10.0*Tosca: " << 10.0*tosca << endl;	//friend operator*

	system("pause");
	return 0;
}