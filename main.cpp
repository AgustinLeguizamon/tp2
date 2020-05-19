#include "file_reader.h"
#include "resource_generator.h"
#include "blocking_queue.h"
#include "worker.h"
#include "thread_spawner.h"
#include "counter.h"
#include "printer.h"

//cpplint
#include <map>
#include <string>
#include <list>

#define ERROR 1

int main(int argc, char const *argv[]){
    FileReader file_reader(argv[1]);

    std::map<std::string, int> workers;
    try {
        workers = file_reader.getMapOfWorkers();
    } catch(FailedToOpenFileException &e){
        return ERROR;
    } catch(InvalidWorkerSyntaxException &e){
        return ERROR;
    }

    file_reader.changeReadingFile(argv[2]);

    std::list<char> resources;
    try {
        resources = file_reader.getResources();
    } catch(FailedToOpenFileException &e){
        return ERROR;
    } catch(InvalidMapCharacterException &e){
        return ERROR;
    }

    BlockingQueue wheat_source;
    BlockingQueue wood_source;
    BlockingQueue iron_and_carbon_source;
    Storage storage;
    Counter profit_counter;

    Printer printer(storage, profit_counter);

    ThreadSpawner thread_spawner(workers);
    thread_spawner.spawnProducersThreads(&storage, profit_counter);
    thread_spawner.spawnWorkersThreads(&storage, wheat_source,
            wood_source, iron_and_carbon_source);

    ResourceGenerator resource_generator(resources,
            wheat_source, wood_source, iron_and_carbon_source);

    resource_generator.run();

    thread_spawner.joinWorkers();

    storage.close();

    thread_spawner.joinProducers();

    printer.showResults();

    resource_generator.freeSources();

    return 0;
}
