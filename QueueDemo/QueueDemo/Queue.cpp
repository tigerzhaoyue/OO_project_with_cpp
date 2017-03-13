#include "Queue.h"


Queue::Queue(int qs):qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue::~Queue()
{
	Node * temp;
	while(front!=nullptr)//while queueis not yet empty
	{
		temp = front;	//save addr of front item	IMPORTANT! (or we would loss the ptr of head)
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items==0;
}

bool Queue::isfull() const
{
	return items==qsize;
}

int Queue::queuecount() const
{
	return items;;
}

//Add item to queue
bool Queue::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node;	//create a node
	//if fail, new throws std::bad_alloc exception
	add->item = item;		//	set node data
	add->next = nullptr;	//	or nullptr
	items++;
	if (front == nullptr)
		front = add;	//	place item at head
	else
		rear->next = add;
	rear = add;
	return true;
}

//place front item into item variable amd remove from queue
bool Queue::dequeueu(Item & item)
{
	if (front == nullptr)
		return false;
	item = front->item;	//	set item to first item in queue
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;

}
