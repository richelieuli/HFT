#ifndef DATAENGINE_H
#define DATAENGINE_H

#include <string>
#include <fstream>
#include "TradeEvent.h"

class DataEngine{
    public:
        DataEngine(const std::string &InputFile);
        ~DataEngine();
        
        bool hasNextEvent();
        TradeEvent getNextEvent();
    private:
        ifstream inputFile;
};



#endif