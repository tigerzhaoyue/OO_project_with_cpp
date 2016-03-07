#include <iostream>
#include <iomanip>
#include "ring.h"
using namespace std;
Ring::Ring(int n){
	pBegin = new Boy[n];	//malloc
	pCurrent = pBegin;
	for(int i = 1; i <= n ; i++){
		pCurrent ->code = i;
		pCurrent -> next = pBegin + i%n ;
		pCurrent = pCurrent -> next ;
	}
	cout << endl ;
	pCurrent = &pBegin[n-1] ;	//initial begin at the last boy
}

void Ring::Count(int m){
	for(int i = 0 ;i < m ; i++){
		pivot = pCurrent ;
		pCurrent = pivot -> next ;
	}
	cout<< "the current is :" << pCurrent->code<<'\n';
}

void Ring::PutBoy(){
	static int numInLine;
	cout << setw(4) << pCurrent -> code <<"out" << '\n';
}

void Ring::ClearBoy(){
	pivot -> next = pCurrent ->next ;
	pCurrent = pivot ;			//clear the current node
}

Ring::~Ring(){
	delete[]pBegin ;			//free the list
}