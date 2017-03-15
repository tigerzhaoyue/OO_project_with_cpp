//make counts() and reports() template funcs,  keep the same with the typename of class

#include <iostream>
using std::cout;
using std::endl;


//template class
template <typename TT>
class HasFriendT
{
private:
	TT item;
	static int ct;

public:
	HasFriendT(const TT & i);
	~HasFriendT();
	template <typename C>
	friend void counts(C & c);		    //pass C & c to counts   (c is a representive of HasFriendT<C>  to use static data int it)
	template <typename C>
	friend void report(C & c);		
};



//initial each type's static data
template <typename TT>
int HasFriendT<TT>::ct = 0;


template<typename TT>
HasFriendT<TT>::HasFriendT(const TT & i) : item(i)
{
	ct++;
}

template<typename TT>
HasFriendT<TT>::~HasFriendT()
{
	ct--;
}


//template friend funcs :
template<typename C>
void counts(C & c)
{
	cout << "template size: " << sizeof(c) << ";";
	cout << "template counts(): " << c.ct << endl;
}



template<typename C>
void report(C & c)
{
	cout << c.item << endl;
}


int main()
{
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.50);
	report(hfi1);
	report(hfi2);		//this is also available
	report(hfdb);
	cout << "counts<int>() output: " << endl;
	counts(hfi1);
	cout << "counts<double>() output: " << endl;
	counts(hfdb);



	system("pause");
	return 0;



}
