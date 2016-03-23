#include <iostream>
using namespace std;

struct item{
	int n;
	int flag ;	// 1mean right  ;   0 mean left
};

int main(){
	struct item pos[5] ,temp;
	int j,index,present_mobile_num;
	for(int i = 0 ; i < 5 ; i++){
		pos[i].n = i+1;
		pos[i].flag = 0 ;
	}
	for(int i = 0; i < 5 ;i++){
			if(pos[i].flag)
				cout << '>' << ' '; 
			else
				cout <<'<' << ' ';
	}	
	cout << endl ;
	for(int i = 0; i < 5 ;i++){
		cout << pos[i].n<< ' ';
	}
	cout<< '\n' << endl;
	for(int i = 2; i<=50 ;i++){
		for(j=0,index = 5,present_mobile_num=1 ; j<5 ; j++){
			if(( (pos[j].flag==0 && j > 0&&pos[j-1].n<pos[j].n) || ( pos[j].flag == 1 && j < 4 && pos[j+1].n < pos[j].n) ) &&(pos[j].n>present_mobile_num)){
				index = j ;
				present_mobile_num = pos[j].n ;
			}
		}
		//cout << index<< endl;
		if(present_mobile_num == 1)
			break;
		for(int i = 0; i<5 ;i++)
			if(pos[i].n>pos[index].n)  pos[i].flag = (pos[i].flag+1)%2 ;
	
		temp.n = pos[index].n ; 
		temp.flag = pos[index].flag ;
		if(pos[index].flag){
			pos[index].n = pos[index+1].n;
			pos[index].flag = pos[index+1].flag;
			pos[index+1].n = temp.n;
			pos[index+1].flag = temp.flag;
		}
		else{
			pos[index].n = pos[index-1].n;
			pos[index].flag = pos[index-1].flag;
			pos[index-1].n = temp.n;
			pos[index-1].flag = temp.flag;
		}
		
		for(int i = 0; i < 5 ;i++){
			if(pos[i].flag)
				cout << '>' << ' '; 
			else
				cout <<'<' << ' ';
		}
		cout << endl ;
		
		for(int i = 0; i < 5 ;i++)		
			cout << pos[i].n<< ' ';
			
		cout<< '\n' << endl;


	}
	return 0;
}
