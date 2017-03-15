//make counts() and reports() template funcs,  keep the same with the typename of class

#include <iostream>
using std::cout;
using std::endl;

//template func declaration
template <typename T>
void counts();
template <typename T>
void report(T &);



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
	friend void counts<TT>();		//	TT as a para of template to counts    to ensure type of counts is the same as HasFriend<TT>
	friend void report< HasFriendT<TT> >(HasFriendT<TT> &);		//	 from HasFriendT<TT> ,we know report keeps up with TT type
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
template<typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriendT<T>) << ";";
	cout << "template counts(): " << HasFriendT<T>::ct << endl;
}




template<typename T>
void report(T & hf)
{
	cout << hf.item << endl;
}


int main()
{
	counts<int>();				//attention to this kind of way to call counts
	HasFriendT<int> hfi1(10);
	HasFriendT<int> hfi2(20);
	HasFriendT<double> hfdb(10.50);
	report(hfi1);
	report< HasFriendT<int> >(hfi2);		//this is also available
	report(hfdb);
	cout << "counts<int>() output: " << endl;
	counts<int>();
	cout << "counts<double>() output: " << endl;
	counts<double>();



	system("pause");
	return 0;



}
