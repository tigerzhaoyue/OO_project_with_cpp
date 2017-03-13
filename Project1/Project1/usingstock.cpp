#include <iostream>
#include "stock.h"

const int STKS = 4;

int main(){
    {
        //creat arrray of objects
        Stock stocks[STKS] = {
            Stock("NanoSmart", 12,20.0),
            Stock("Boffo Objects",200,2.0),
            Stock("Monolithic Obelisks", 130,3.25),
            Stock("Fleep Enterprise",60,6.5)
        };

        std::cout << "Stock holdings:"<<std::endl;
        int st;
        for(st = 0 ; st < STKS ; st++)
            stocks[st].show();
        //set pointer to first element
        const Stock *top = &stocks[0];
        for(st = 1 ; st<STKS ; st++){
            top = &top->topval(stocks[st]);
        }
        //now top points to the highest one
        std::cout << "\n Most valuable holding:"<<std::endl;
        top->show();
    }
    system("pause");
    return 0;
}