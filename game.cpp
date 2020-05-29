//
// Created by agustin on 29/5/20.
//

#include "game.h"
#include "blocking_queue.h"
#include "counter.h"
#include "storage.h"
#include "printer.h"
#include "thread_spawner.h"
#include "resource_generator.h"

Game::Game(const char *argv[]) : file_reader(argv[1], argv[2]){
    workers = file_reader.getMapOfWorkers();
    resources = file_reader.getResources();
}

void Game::operator()() {
    BlockingQueue wheat_source;
    BlockingQueue wood_source;
    BlockingQueue iron_and_carbon_source;
    Storage storage;
    Counter profit_counter;

    Printer printer(storage, profit_counter);

    ThreadSpawner thread_spawner(workers);
    thread_spawner.spawnProducersThreads(storage, profit_counter);
    thread_spawner.spawnWorkersThreads(storage, wheat_source,
                                       wood_source, iron_and_carbon_source);

    ResourceGenerator resource_generator(resources,
            wheat_source, wood_source, iron_and_carbon_source);

    resource_generator.run();

    thread_spawner.joinWorkers();

    storage.close();

    thread_spawner.joinProducers();

    printer.showResults();
}
