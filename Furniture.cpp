#include <iostream>
using namespace std ;

class Furniture {
public:
	Furniture(){
		cout << "Initial a Furniture." << endl ;
	}
	void Setweight(int x){
		weight = x ;
		return ;
	}
	int Getweight(){
		cout << weight << endl ;
	}
	~Furniture(){
		cout << "delete the Furniture." << endl ;
	}
protected:
	int weight ;
};

class Bed : virtual public Furniture{
public:
	Bed() : Furniture(){
		cout << "Initial a bed." << endl ;
	}
	void Sleep(){
		cout << "Sleep on Bed now." << endl ;
	}
	~Bed(){
		cout << "delete the Bed ." << endl ;
	}
};

class Sofa : virtual public Furniture{
public:
	Sofa() : Furniture(){
		cout << "Initial a sofa." << endl ;
	}
	void WatchTV(){
		cout << "Watching TV now." << endl ;
	}
	~Sofa(){
		cout << "delete the sofa. " << endl ;
	}
};

class SleepSofa : public Bed , public Sofa{
public:
	SleepSofa() : Sofa(),Bed(){
		cout << "Initial a SleepSofa." << endl ;
	}
	void FoldOut(){
		cout << "Fold out the Sofa." << endl ;
	}
	~SleepSofa(){
		cout << "delete the Sleepsofa." << endl ;
	}
};
int main(){
	SleepSofa obj ;
	Bed bd ;
	obj.Setweight(100) ;
	obj.Getweight() ;
	obj.FoldOut() ;
	obj.WatchTV() ;
	bd.Setweight(50) ; 
	bd.Getweight() ;
	return 0;
}



