//stock.cpp 
#include <iostream>
#include "stock.h"

//constructor
Stock::Stock()
{
    company = "NULL";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    company = co;
    if(n<0){
        std::cout << "Number of shares can't be negative!"<<company << "shares set to 0."<<std::endl;
        shares = 0; 
    }
    else{
        shares = n;
    }
    share_val = pr;
    set_tot();
}

//destructor
Stock::~Stock()
{
    std::cout << company << "Destructed!" <<std::endl;
}

// other methods
void Stock::buy(long num, double price)
{
    if(num<0){
        std::cout << "Number of shares purchased can't be negative!" <<std::endl;
    }
    else{
        shares = shares+num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if(num<0){
        std::cout <<"Number of shares sold can't be negative!"<<std::endl;
    }
    else if (num>shares){
        std::cout << "You cannot sell more than you have!"<<std::endl;
    }
    else{
        shares = shares-num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()const
{
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "company:" << company <<" Shares: " << shares <<std::endl;
    cout <<" Share price: $" << share_val;

    //set format to #.##
    cout.precision(2);
    cout << " Total Worth: $" << total_val <<std::endl;

    //restore original format
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec); 
}

const Stock & Stock::topval(const Stock & s)const
{
    if(s.total_val>total_val)
        return s;
    else
        return *this;
}



