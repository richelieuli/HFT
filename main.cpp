#include "DataEngine.h"
#include "LOB.h"
#include <iostream>
#include <string>

int main(){
    long long int i = 0;
    DataEngine de = DataEngine("C:\\Users\\l514w\\Q\\HFT4crypto\\data\\BTCBUSD-trades-2023-12.csv");
    LimitOrderBook lob = LimitOrderBook();
    while(de.hasNextEvent()){
        TradeEvent te = de.getNextEvent();
        lob.update(te);
        i = i+1;
        if (i%10000){
            cout<<lob.best_ask().price<<endl;
        }
    }
}

