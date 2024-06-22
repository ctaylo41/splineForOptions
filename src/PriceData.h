#ifndef PRICEDATA_H
#define PRICEDATA_H

#include <vector>

class PriceData {
public:
    std::vector<double> close;
    std::vector<double> high;
    std::vector<double> low;
    std::vector<double> numTrades;
    std::vector<double> open;
    std::vector<double> timestamp;
    std::vector<double> volume;
    std::vector<double> vwap;

    PriceData(int count) {
        close.resize(count);
        high.resize(count);
        low.resize(count);
        numTrades.resize(count);
        open.resize(count);
        timestamp.resize(count);
        volume.resize(count);
        vwap.resize(count);
    };
};
#endif