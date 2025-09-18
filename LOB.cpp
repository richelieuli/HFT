#include "LOB.h"
#include "TradeEvent.h"
LimitOrderBook::LimitOrderBook(void)
{
    cout<<"LOB got created";
}

Order LimitOrderBook::best_bid()
{
    if (sorted_bid.empty()) {
        return Order(0,0); // 判空逻辑
    }
    return sorted_bid.top();
}

Order LimitOrderBook::best_ask()
{
    if (sorted_ask.empty()) {
        return Order(0,0); // 判空逻辑
    }
    return sorted_ask.top();
}

double LimitOrderBook::search(Orderside type, double price)
{
    if (type == BID)
        return  LOB_bid[price];
    else
        return LOB_ask[price];
}

void LimitOrderBook::update(TradeEvent te)
{
    if (te.isBuyerMaker==true){
        if (LOB_ask[te.price]){
            LOB_ask[te.price]-=te.quantity;
        }
        else{
            LOB_ask.insert({te.price, te.quantity}); 
        }
    }
    else{
        if (LOB_bid[te.price]){
            LOB_bid[te.price]-=te.quantity;
        }
        else{
            LOB_bid.insert({te.price, te.quantity}); 
        }
    }
}