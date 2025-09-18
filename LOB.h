#include "TradeEvent.h"
#include <unordered_map>
#include <memory>
#include <string>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

enum Orderside{BID,
ASK
};

class Order{
    public:
    double price;
    double quantity;

    Order(double p, double q): price(p), quantity(q) {};
};


struct CompareBid{
    bool operator()(Order& a, Order& b){
        return a.price<b.price;
    }
};

struct CompareAsk{
    bool operator()(Order& a, Order& b){
        return a.price>b.price;
    }
};

class LimitOrderBook{
    private:
        priority_queue <Order, vector<Order>, CompareBid>sorted_bid;
        priority_queue <Order, vector<Order>, CompareAsk>sorted_ask;
        unordered_map <double, double> LOB_bid;
        unordered_map <double, double> LOB_ask;
    public:
        LimitOrderBook();
        ~LimitOrderBook(){};
        double search(enum Orderside, double price);
        Order best_bid();
        Order best_ask();
        void update(TradeEvent te);
};
