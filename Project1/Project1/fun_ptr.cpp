//fun_ptr.cpp -- pointers to functions
#include <iostream>
double ZhaoYue(int);
double wpx(int);

//second argument is pointer to a type double function that 
//takes a type int argument

void estimate(int lines, double (*pf)(int));

int main(){
    using namespace std;
    int code;
    cout << "How many lines of code do you need?";
    cin >> code;
    cout << "Here's ZhaoYue's estimate:" << endl;
    estimate(code,ZhaoYue);
    cout << "Here's wpx's estimate" << endl;
    estimate(code,wpx);
	system("pause");
    return 0;
}

double ZhaoYue(int lns){
    return 0.05 * lns ;
}

double wpx(int lns){
    return 0.03 * lns + 0.0004 * lns * lns ;

}

void estimate(int lines , double (*pf)(int)){
    using namespace std;
    cout << lines << "Lines will take ";
    cout << (*pf)(lines) << "hour(s)" << endl;
}