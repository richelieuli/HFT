#include <fstream>
#include "DataEngine.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

bool DataEngine::hasNextEvent() {
    // 检查文件流是否打开且没有到达文件末尾
    return inputFile.is_open() && !inputFile.eof();
}

// 构造函数：在这里打开文件
DataEngine::DataEngine(const string &filePath) {
    inputFile.open(filePath);
    if (!inputFile.is_open()) {
        // 错误处理：如果文件无法打开，可以打印错误信息或抛出异常
        // For now, let's just print a message
        cerr << "Error: Unable to open file " << filePath << endl;
    }
}

// 析构函数：在这里关闭文件
DataEngine::~DataEngine() {
    if (inputFile.is_open()) {
        inputFile.close();
    }
}

TradeEvent DataEngine::getNextEvent(){
    string line;
    if(getline(inputFile, line)){
        stringstream ss(line);
        string cell;

        TradeEvent event;

        getline(ss, cell, ',');
        event.tradeId = stoll(cell);

        std::getline(ss, cell, ',');
        event.price = std::stod(cell);
        
        std::getline(ss, cell, ',');
        event.quantity = std::stod(cell);

        std::getline(ss, cell, ',');
        event.quoteQty = std::stod(cell);

        std::getline(ss, cell, ',');
        event.time = std::stoll(cell);

        getline(ss, cell, ',');
        event.isBuyerMaker = (cell == "True" || cell == "true"); 

        getline(ss, cell, ',');
        event.isBestMatch = (cell == "True" || cell == "true");


        return event;
    }
    return TradeEvent();
}
