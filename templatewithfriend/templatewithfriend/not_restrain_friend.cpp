//we needn't to delclare a template func out of class
//in class we can make friend to a template 
//and this template needn't match the typename of class
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
	T item;

public:
	ManyFriend(const T & i);
	template <typename C, typename D>
	friend void show(C & c, D & d);			//again   no need a specific name of paras

};


template<typename T>
ManyFriend<T>::ManyFriend(const T & i) : item(i)
{
}



template <typename C, typename D>
void show(C & c, D & d)
{
	cout << c.item << "," << d.item << endl;
}

int main()
{
	ManyFriend<int> hfi1(10);
	ManyFriend<int> hfi2(20);
	ManyFriend<double> hfdb(10.50);
	cout << "hfi1, hfi2: ";
	show(hfi1, hfi2);
	cout << "hfdb, hfi2: ";
	show(hfdb, hfi2);

	system("pause");
	return 0;

}


