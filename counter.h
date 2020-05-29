//
// Created by agustin on 12/5/20.
//

#ifndef TP2CLION_COUNTER_H
#define TP2CLION_COUNTER_H


#include <mutex>

class Counter {
private:
    unsigned int total_profit_points;
    std::mutex mutex;

public:
    Counter();

    Counter(const Counter& other) = delete;

    void add(unsigned int profit_points);

    unsigned int getPoints();
};


#endif //TP2CLION_COUNTER_H
