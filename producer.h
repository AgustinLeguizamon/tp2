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
    virtual void sayWhatProducerYouAre() = 0;
    void operator()();
};

class Cook : public Producer{
public:
    explicit Cook(Storage* storage, Counter& counter);
    void sayWhatProducerYouAre() override;
    //void operator()() override ;
};


class Carpenter : public Producer{
public:
    explicit Carpenter(Storage* storage, Counter& counter);
    void sayWhatProducerYouAre() override;
};

class Gunsmith : public Producer{
public:
    explicit Gunsmith(Storage* storage, Counter& counter);
    void sayWhatProducerYouAre() override;
};


#endif //TP2CLION_PRODUCER_H
