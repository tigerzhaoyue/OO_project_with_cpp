//a class wtih non-template friend funcs
//after make a new template class, we should define many similar friend func with different type of para

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class HasFriend
{
private:
	T item;
	static int ct;	//	conut of a class 

public:
	HasFriend(const T & i);	//use T type to construct
	~HasFriend();
	friend void counts();
	friend void reports(HasFriend<T> &);	//	template parameters     no specific name
};


//each specialization has its own static data
template <typename T>
int HasFriend<T>::ct = 0;


//construct & destruct
template<typename T>
HasFriend<T>::HasFriend(const T & i) : item(i)
{
	ct++;
}

template<typename T>
HasFriend<T>::~HasFriend()
{
	ct--;
}



//all typename can use the same func bacause it has no para
void counts()		//show two different class (HasFriend<int> and HasFriend<double>  numbers )
{
	cout << "int count: " << HasFriend<int>::ct << ";";
	cout << "double count: " << HasFriend<double>::ct << ";" << endl;
}




//define different kinds of specific friend funcs here

//non-template friend to the HasFriend<int> class
void reports(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

//non-template friend to the HasFriend<double> class
void reports(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}


int main()
{
	cout << "No objects declared: ";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfil1 declared:";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfil2 declared:";
	counts();
	HasFriend<double> hfdb(10.50);
	cout << "After hfdb declared:";
	counts();
	reports(hfi1);
	reports(hfi2);
	reports(hfdb);

	system("pause");
	return 0;
}

