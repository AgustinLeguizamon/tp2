//
// Created by agustin on 12/5/20.
//

#include <iostream>
#include "counter.h"

Counter::Counter() :
    total_profit_points(0)
    {}

void Counter::add(const unsigned int profit_points) {
    std::unique_lock<std::mutex> lock(mutex);
    total_profit_points += profit_points;
 }


unsigned int Counter::getPoints() const{
    return total_profit_points;
}
