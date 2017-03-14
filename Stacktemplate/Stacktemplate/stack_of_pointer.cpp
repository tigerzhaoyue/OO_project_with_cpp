//stack_of_pointer.cpp -- use Stack template to place some pointers to char[] 
//if coin is positive  get a string from in[], if coin is neg   send a string to out[]   until process all Num string .
//buffer is a stack structure    using Stack<const char *> to store pointers  of strings
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

const int Num = 10;

int main()
{
	std::srand(std::time(0));
	std::cout << "Please enter stack size:";
	int stacksize;
	std::cin >> stacksize;
	//create an empty stack with stacksize
	Stack<const char *> st(stacksize);

	//in basket
	const char * in[Num] =
	{
		"1.fhdjhfsjkhjk",
		"2.dfhjsdhfkdjshfk",
		"3.fhjdhfjdshgkdj",
		"4.dfhjdhfksjd",
		"5.kjgjgrehjpe",
		"6.hfhgljdshgsh",
		"7.qijqjgklwg",
		"8.dfhljfhlghl",
		"9.dfhhgjlsg",
		"10.fhjhgjkdgkshjg"
	};
	//out of basket
	const char * out[Num];
	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
	{
		std::cout << out[i] << std::endl;
	}
	std::cout << "Done!" << std::endl;

	system("pause");
	return 0;


	
}