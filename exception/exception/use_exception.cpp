//use_Sales.cpp -- nested exceptions

#include <iostream>
#include "Sales.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;


	double vals1[12] =
	{ 1220,1100,1122,2212,1232,2234,
	  2886,2393,3302,2922,3002,3544
	};

	double vals2[12] =
	{ 12,11,22,21,32,34,
	  28,29,33,29,32,39
	};


	Sales sales1(2016, vals1, 12);
	LabeledSales sales2("Zhao Yue", 2017, vals2, 12);

	cout << "First try block:\n";
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << " ";
			if (i % 6 == 5)
				cout << endl;	//	change line
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for(i=0;i<=12;++i)
		{
			cout << sales2[i] << " ";
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of tyr block!" << endl;
	}
	catch (LabeledSales::nbad_index & bad)		//bad is just a symbol   not important    like a func para declar
	{
		cout << bad.what();
		cout << "Label: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index & bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}



	cout << "\nNext block: " << endl;



	try
	{
		//call double & Sales::operator[](int i);
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n";
	}
	catch(LabeledSales::nbad_index & bad)			//have to catch child exception firt.
	{
		cout << bad.what();
		cout << "Label: " << bad.label_val() << endl;
		cout << "bad index: " << bad.bi_val() << endl;
	}
	catch (Sales::bad_index & bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl;
	}


	cout << "DONE\n";
	system("pause");
	return 0;

}