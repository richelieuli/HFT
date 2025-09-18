#ifndef TRADEEVENT_H
#define TRADEEVENT_H

#include <string>

using namespace std;

class TradeEvent{
    public:
        long long tradeId;      // 交易ID
        double price;           // 成交价格
        double quantity;        // 数量
        double quoteQty;        // 交易额
        long long time;         // 时间戳
        bool isBuyerMaker;      // 是否为买方 Maker
        bool isBestMatch;       // 是否为最佳匹配
};

#endif