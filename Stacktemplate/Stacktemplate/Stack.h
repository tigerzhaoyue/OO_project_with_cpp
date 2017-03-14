//Stack.h -- a template of stack
#pragma once

template <typename T>	//or template <class T>
class Stack
{
private:
	enum { SIZE = 15 };
	int stacksize;
	T * items;			//addr of array of items
	int top;			//point to the first AVAILABLE place
public:
	explicit Stack(int ss = SIZE);	//avoid  Stack<T> = 123456      using explicit
	Stack(const Stack & st);		//override copy func
	~Stack();						
	bool isempty() { return top == 0; }
	bool isfull() { return top == stacksize; }
	bool push(const T & item);
	bool pop(T & item);
	Stack & operator=(const Stack & st);
};






//inplements:

template<typename T>
Stack<T>::Stack(int ss) : stacksize(ss), top(0)
{
	items = new T[stacksize];
}

template<typename T>
Stack<T>::Stack(const Stack & st)
{
	stacksize = st.stacksize;
	top = st.top;
	items = new T[stacksize];
	for (int i = 0; i < stacksize; i++)
		items[i] = st.items[i];
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] items;
}


template<typename T>
bool Stack<T>::push(const T & item)
{
	if (top < stacksize)
	{
		items[top++] = item;
		return  true;
	}
	else
		return false;
}

template<typename T>
bool Stack<T>::pop(T & item)
{
	if (top>0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

template<typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & st)
{
	// TODO: 在此处插入 return 语句
	if (this == st)
		return *this;	//if point to one thing    just return it
	delete[] items;		//remove the already items in *this
						//from here  same as copy func
	stacksize = st.stacksize;
	top = st.top;
	items = new T[stacksize];
	for (int i = 0; i < stacksize; i++)
		items[i] = st.items[i];
	return *this;
}
