//
// Created by agustin on 10/5/20.
//

#include <unistd.h>
#include "producer.h"

#define COOK_PROFIT_POINTS 5
#define COOK_WHEAT_CONSUMPTION 2
#define COOK_WOOD_CONSUMPTION 0
#define COOK_IRON_CONSUMPTION 0
#define COOK_CARBON_CONSUMPTION 1
#define CARPENTER_PROFIT_POINTS 2
#define CARPENTER_WHEAT_CONSUMPTION 0
#define CARPENTER_WOOD_CONSUMPTION 3
#define CARPENTER_IRON_CONSUMPTION 1
#define CARPENTER_CARBON_CONSUMPTION 0
#define GUNSMITH_PROFIT_POINTS 3
#define GUNSMITH_WHEAT_CONSUMPTION 0
#define GUNSMITH_WOOD_CONSUMPTION 0
#define GUNSMITH_IRON_CONSUMPTION 2
#define GUNSMITH_CARBON_CONSUMPTION 2
#define MS_PRODUCER_SLEEP 60000

Producer::Producer(Storage *storage, Counter& counter,
        unsigned int profit_points, unsigned int wheat,
        unsigned int wood, unsigned int iron, unsigned int carbon) :
    storage(storage),
    counter(counter),
    profit_points(profit_points),
    is_producing(true) ,
    wheat_consumption(wheat),
    wood_consumption(wood),
    iron_consumption(iron),
    carbon_consumption(carbon)
    {}

Cook::Cook(Storage *storage, Counter& counter) :
    Producer(storage, counter, COOK_PROFIT_POINTS, COOK_WHEAT_CONSUMPTION,
            COOK_WOOD_CONSUMPTION, COOK_IRON_CONSUMPTION,
            COOK_CARBON_CONSUMPTION )
    {}

Carpenter::Carpenter(Storage *storage, Counter& counter) :
        Producer(storage, counter, CARPENTER_PROFIT_POINTS,
                CARPENTER_WHEAT_CONSUMPTION,
                 CARPENTER_WOOD_CONSUMPTION, CARPENTER_IRON_CONSUMPTION,
                 CARPENTER_CARBON_CONSUMPTION )
    {}

Gunsmith::Gunsmith(Storage *storage, Counter &counter) :
    Producer(storage, counter, GUNSMITH_PROFIT_POINTS,
            GUNSMITH_WHEAT_CONSUMPTION, GUNSMITH_WOOD_CONSUMPTION,
            GUNSMITH_IRON_CONSUMPTION, GUNSMITH_CARBON_CONSUMPTION )
    {}

void Producer::operator()() {
    while (is_producing){
        try{
            //consume los recursos
            storage->consumeResources(wheat_consumption,wood_consumption,
                    iron_consumption, carbon_consumption);
            usleep(MS_PRODUCER_SLEEP);//duermo
            //deposito los puntos de beneficio
            this->counter.add(profit_points);
        } catch(ClosedStorageException& e){
            this->is_producing = false;
        }
    }
}

void Cook::sayWhatProducerYouAre() {
    std::cout << "i'm Cook: " << profit_points << std::endl;
}

void Carpenter::sayWhatProducerYouAre() {
    std::cout << "i'm Carpenter: " << profit_points << std::endl;
}

void Gunsmith::sayWhatProducerYouAre() {
    std::cout << "i'm Gunsmith: " << profit_points << std::endl;
}
