//Queue.h -- container of customers
#pragma once
#include "Customer.h"
typedef Customer Item;

class Queue
{
private:
	//class scope definition:
	struct Node
	{
		Item item;
		struct Node * next;
	};

	enum 
	{ Q_SIZE = 10 };
	//private class members:
	Node * front;			//pointer to front of Queue
	Node * rear;			//pointer to rear of Queue
	int items;				//how many items in Queue
	const int qsize;		//MAX number of items in Queue

	////////////////////////////////////////////////////////////////////////////
	//TODO  override these 2 funcs
	//
	//tricks to prevent public COPYING (we don't have deep-copy methods ,so.....)
	Queue(const Queue & q) :qsize(0) {}						//overload copy func
	Queue & operator=(const Queue & q) { return *this; }	//	overload assign op
	////////////////////////////////////////////////////////////////////////////
	
public:
	Queue(int qs = Q_SIZE);	//	CREATE QUEUE with a qs limit
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item & item);	//	push_back item
	bool dequeueu(Item & item);			//remove item form front

};

