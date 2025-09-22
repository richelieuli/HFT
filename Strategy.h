#include "TradeEvent.h"
#include "LOB.h"
#include <vector>

class Strategy{
    public:

    virtual void onTrade(const TradeEvent& trade) = 0;
    virtual void onOrderBookUpdate(const LimitOrderBook& lob_snapshot) = 0;

    virtual std::vector<Order> getOrders() = 0;
};