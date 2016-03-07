#include <iostream>
#include <iomanip>
using namespace std; 
struct Jose{
	int code;
	Jose* next;
};	//node of a child

//global:
int n ;		//num of children
int begin ;	//start position
int m ;		//counting length
Jose* pivot;	//witness
Jose* pCur;	//the node at present

//func declaration:
int assign();			//initial the num return 1or 0
void initial(Jose* pBoys);	//initial the list
void count(int m);		//count m children
void process();			//deal the children left

//main:
int main()
{
	if(!assign()){
		cout << "The program failed.\n" ;
		return 0;
	}
	Jose* pJose  = new Jose[n] ;		//malloc space	      and       pJose is the head of the list
	initial(pJose) ;				//initial the list
	count(begin) ;				//goto the start position
	process() ;				//deal the left

	cout << "\nthe winner is  " << pCur -> code << endl ;

	delete[]pJose;
	return 0;
}


int assign(){
	int number, start , count ;
	cout << "Please input the number , begin , count : \n" ;
	cin >> number >> start >> count ;

	if(number < 2){
		cerr << "bad number of boys.\n" ;
		return 0;
	}

	if(start < 0){
		cerr << "bad start position.\n" ;
		return 0;
	}

	if(count < 1 || count > number){
		cerr << "bad interval number.\n" ;
		return 0;
	}

	n = number ;
	begin = start -1 ;
	m = count;	//initial the key words
	return 1;
}


//initial the list:
void initial(Jose* pJose){
	int LineCount = 0 ;
	Jose* px = pJose ;
	for(int i =1 ; i <= n ; i++){
		px -> next = pJose + i%n ;	//the method to initial a circle
		px -> code = i ;
		px = px -> next;

		if((LineCount ++%10) == 0)	//a line is filled of 10 nums
			cout << endl ;
		cout << setw(4) << i ;
	}
	cout << endl ;
	pCur = pJose +n -1;	//point the last item
}


//count:
void count (int m){
	for(int i = 0; i < m ; i++){
		pivot = pCur;
		pCur = pivot ->next ;
	}
}

//process:
void process(){
	int left = 0;
	for(int i = 1 ; i < n ; i ++){
		count(m) ;	//count m children

		if((left ++ %10) == 0)
			cout << endl ;
		cout << setw(4) << pCur ->code ;	//go out the list
		pCur = pivot ;
	}
}
