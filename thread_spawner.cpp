//
// Created by agustin on 10/5/20.
//

#include "thread_spawner.h"
#include "producer.h"
//cpplint
#include <map>
#include <string>

ThreadSpawner::ThreadSpawner(std::map<std::string, int> &workers) :
        workers(workers)
{}

void ThreadSpawner::spawnProducersThreads(Storage *p_storage,
        Counter &counter) {
    this->spawnCooks(p_storage, counter);
    this->spawnCarpenters(p_storage, counter);
    this->spawnGunSmiths(p_storage, counter);
}

void ThreadSpawner::spawnWorkersThreads(Storage *p_storage,
        BlockingQueue &wheat_source, BlockingQueue &wood_source,
        BlockingQueue &iron_and_carbon_source) {
    int n_farmers = workers["Agricultores"];
    int n_woodcutters = workers["Leniadores"];
    int n_miners = workers["Mineros"];

    int total_gatherers = n_farmers + n_woodcutters + n_miners;
    gatherers.reserve(total_gatherers);
    for (int i = 0; i < n_farmers; ++i) {
        gatherers.emplace_back(&wheat_source, p_storage);
    }
    for (int i = 0; i < n_woodcutters; ++i) {
        gatherers.emplace_back(&wood_source, p_storage);
    }
    for (int i = 0; i < n_miners; ++i) {
        gatherers.emplace_back(&iron_and_carbon_source, p_storage);
    }
    workers_threads.reserve(gatherers.size());
    for (auto & worker : gatherers) {
        workers_threads.emplace_back(std::ref(worker));
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
