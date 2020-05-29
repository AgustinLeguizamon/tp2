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

    /*Agrega el @param profit_points a total_profit_points*/
    void add(unsigned int profit_points);

    /*Devuelve total_profit_points*/
    unsigned int getPoints() const;
};


#endif //TP2CLION_COUNTER_H
