//template_and_overload.cpp -- using template_and_overload template functions
#ifndef HAHA
#define HAHA
#include <iostream>

template <typename T>   //original template function
void Swap(T &a, T &b);

template <typename T>   //  New template function
void Swap(T *a, T *b, int n);   //  different para list
void Show (int a[]);
const int Lim = 8;

int main(){
    using namespace std;
    int i =10,j=20;
    cout << "i,j = " << i << "," << j << endl;
    cout << "Using conpiler0generated int swapper:"<<endl;
    Swap(i,j);  //  matching original template
    cout << "Now i,j=:"<<i<<","<<j<<"."<<endl;

    int d1[Lim] = {0,7,0,4,1,7,7,6};
    int d2[Lim] = {0,7,2,0,1,9,6,9};

    cout << "Original array:" << endl;
    Show(d1);
    Show(d2);
    Swap(d1,d2,Lim);    //matching new template
    cout << "Swapped array:"<<endl;
    Show(d1);
    Show(d2);
    //cin.get();
    system("pause");
    return 0;
}

template <typename T>
void Swap(T &a,T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
void Swap(T a[], T b[],int n){
    T temp;
    for(int i = 0 ; i < n ; i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

void Show(int a[]){
    using namespace std;
    cout << a[0] <<a[1] <<"/";
    cout << a[2] << a[3] <<"/";
    for(int i = 4; i < Lim ; i++ ){
        cout <<a[i];
    }
    cout <<endl;
}

#endif