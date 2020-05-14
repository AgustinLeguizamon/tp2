//
// Created by agustin on 10/5/20.
//

#ifndef TP2CLION_THREAD_SPAWNER_H
#define TP2CLION_THREAD_SPAWNER_H


#include <string>
#include <map>
#include <thread>
#include "blocking_queue.h"
#include "worker.h"
#include "counter.h"
#include "producer.h"

//cpplint
#include <vector>

class ThreadSpawner {
private:
    std::map<std::string, int>& workers;
    std::vector<std::thread> workers_threads;
    std::vector<std::thread> producers_threads;
    std::vector<Cook> cooks;
    std::vector<Carpenter> carpenters;
    std::vector<Gunsmith> gunsmiths;
    std::vector<Worker> farmers;
    std::vector<Worker> woodcutters;
    std::vector<Worker> miners;

public:
    explicit ThreadSpawner(std::map<std::string, int> &workers);

    void spawnWorkersThreads();

    void spawnFarmers(BlockingQueue *p_source, Storage *p_storage);

    void spawnWoodCutters(BlockingQueue *p_source, Storage *p_storage);

    void spawnMiners(BlockingQueue *p_source, Storage *p_storage);

    void spawnCooks(Storage* p_storage, Counter &counter);

    void spawnCarpenters(Storage *p_storage, Counter &counter);

    void joinWorkers();

    void joinProducers();

    void spawnGunSmiths(Storage *p_storage, Counter &counter);
};


#endif //TP2CLION_THREAD_SPAWNER_H
