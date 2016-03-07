#include <iostream>
#include <iomanip>
#include "Jose.h"
#include "ring.h"
using namespace std;

void Jose::Initial(){
	int num,begin,m;
	cout << "Please input the number of boys, begin position, and interval per count :\n" ;
	cin >> num >> begin >> m ;
	if(num < 2){
		cerr << "bad number of boys.\n";
		return ;
	}
	if(begin < 0){
		cerr << "bad number of begin positon.\n" ;
		return ;
	}
	if(m < 1 || m > num){
		cerr << "bad number of interval number.\n" ;
		return ;
	}

	//else,  the number is legal
	numOfBoys = num ;
	beginPos = begin ;
	interval = m ;
}

void Jose::GetWinner(){
	Ring x(numOfBoys);
	x.Count(beginPos);	//goto the begin position

	for(int i =1 ; i < numOfBoys ; i++){
		x.Count(interval) ;	//count 
		x.PutBoy() ;	//cout the out-boy
		x.ClearBoy() ;	//clear the out-boy
				//game continue
	}
	cout << "The winner is : " ;
	x.PutBoy() ;		//cout the final boy
}
