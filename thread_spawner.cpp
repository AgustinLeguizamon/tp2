//
// Created by agustin on 10/5/20.
//

#include "thread_spawner.h"
#include "producer.h"
//cpplint
#include <map>
#include <string>

void ThreadSpawner::spawnWorkersThreads() {
    //aca llamo a los 6 metodos privados spawner
}

ThreadSpawner::ThreadSpawner(std::map<std::string, int> &workers) :
     workers(workers)
     {}

void ThreadSpawner::spawnFarmers(BlockingQueue *p_source,
        Storage *p_storage) {
    int n = workers["Agricultores"];

    farmers.reserve(n);
    for (int i = 0; i < n; ++i) {
        farmers.emplace_back(p_source, p_storage);
    }

    workers_threads.reserve(farmers.size());
    for (auto & farmer : farmers) {
        workers_threads.emplace_back(std::ref(farmer));
    }
}

void ThreadSpawner::spawnWoodCutters(BlockingQueue *p_source,
        Storage *p_storage) {
    int n = workers["Leniadores"];

    woodcutters.reserve(n);
    for (int i = 0; i < n; ++i) {
        woodcutters.emplace_back(p_source, p_storage);
    }

    workers_threads.reserve(woodcutters.size());
    for (auto & wood_cutter : woodcutters) {
        workers_threads.emplace_back(std::ref(wood_cutter));
    }
}

void ThreadSpawner::spawnMiners(BlockingQueue *p_source,
        Storage *p_storage) {
    int n = workers["Mineros"];

    miners.reserve(n);
    for (int i = 0; i < n; ++i) {
        miners.emplace_back(p_source, p_storage);
    }

    workers_threads.reserve(miners.size());
    for (auto & miner : miners) {
        workers_threads.emplace_back(std::ref(miner));
    }
}

void ThreadSpawner::spawnCooks(Storage *p_storage, Counter &counter) {
    int n_cook = workers["Cocineros"];

    cooks.reserve(n_cook);
    for (int i = 0; i < n_cook; ++i) {
        cooks.emplace_back(p_storage, counter);
    }

    producers_threads.reserve(cooks.size());
    for (auto & cook : cooks) {
        producers_threads.emplace_back(std::ref(cook));
    }
}


void ThreadSpawner::spawnCarpenters(Storage *p_storage, Counter &counter) {
    int n_carpenter = workers["Carpinteros"];
    carpenters.reserve(n_carpenter);
    for (int i = 0; i < n_carpenter; ++i) {
        carpenters.emplace_back(p_storage, counter);
    }

    producers_threads.reserve(carpenters.size());
    for (auto & carpenter : carpenters) {
        producers_threads.emplace_back(std::ref(carpenter));
    }
}

void ThreadSpawner::spawnGunSmiths(Storage *p_storage, Counter &counter) {
    int n_gunsmiths = workers["Armeros"];
    gunsmiths.reserve(n_gunsmiths);
    for (int i = 0; i < n_gunsmiths; ++i) {
        this->gunsmiths.emplace_back(p_storage, counter);
    }

    producers_threads.reserve(gunsmiths.size());
    for (auto & gunsmith : gunsmiths) {
        this->producers_threads.emplace_back(std::ref(gunsmith));
    }
}

void ThreadSpawner::joinWorkers() {
    for (auto & workers_thread : workers_threads) {
        workers_thread.join();
    }
}

void ThreadSpawner::joinProducers() {
    for (auto & producers_thread : producers_threads) {
        producers_thread.join();
    }
}
