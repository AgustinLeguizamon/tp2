//
// Created by agustin on 10/5/20.
//

#ifndef TP2CLION_PRODUCER_H
#define TP2CLION_PRODUCER_H


#include "storage.h"
#include "counter.h"

class Producer {
protected:
    Storage* storage;
    Counter& counter;
    const unsigned int profit_points;
    bool is_producing;
    const unsigned int wheat_consumption;
    const unsigned int wood_consumption;
    const unsigned int iron_consumption;
    const unsigned int carbon_consumption;

public:
    explicit Producer(Storage* storage, Counter& counter,
            unsigned int profit_points, unsigned int wheat,
            unsigned int wood, unsigned int iron,
            unsigned int carbon);
    void operator()();
};

class Cook : public Producer{
public:
    explicit Cook(Storage* storage, Counter& counter);
};


class Carpenter : public Producer{
public:
    explicit Carpenter(Storage* storage, Counter& counter);
};

class Gunsmith : public Producer{
public:
    explicit Gunsmith(Storage* storage, Counter& counter);
};


#endif //TP2CLION_PRODUCER_H
