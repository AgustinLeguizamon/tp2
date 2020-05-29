//
// Created by agustin on 10/5/20.
//

#ifndef TP2CLION_THREAD_SPAWNER_H
#define TP2CLION_THREAD_SPAWNER_H


#include <string>
#include <map>
#include <thread>
#include "producer.h"
#include "worker.h"

//cpplint
#include <vector>

class Counter;
class BlockingQueue;
class Producer;
class ThreadSpawner {
private:
    std::map<std::string, int>& workers;
    std::vector<std::thread> workers_threads;
    std::vector<std::thread> producers_threads;
    std::vector<Cook> cooks;
    std::vector<Carpenter> carpenters;
    std::vector<Gunsmith> gunsmiths;
    std::vector<Worker> gatherers;

public:
    explicit ThreadSpawner(std::map<std::string, int> &workers);

    /*Lanza los hilos de todos los productores*/
    void spawnProducersThreads(Storage &storage, Counter &counter);

    /*Lanza los hilos de todos los recolectores*/
    void spawnWorkersThreads(Storage &storage, BlockingQueue &wheat_source,
                             BlockingQueue &wood_source,
                             BlockingQueue &iron_and_carbon_source);

    /*Joinea los hilos de recolectores*/
    void joinWorkers();

    /*Joinea los hilos de los productores*/
    void joinProducers();

private:
    /*Lanza los hilos de cocineros*/
    void spawnCooks(Storage &storage, Counter &counter);

    /*Lanza los hilos de armeros*/
    void spawnGunSmiths(Storage &storage, Counter &counter);

    /*Lanza los hilos de carpinteros*/
    void spawnCarpenters(Storage &storage, Counter &counter);
};


#endif //TP2CLION_THREAD_SPAWNER_H
