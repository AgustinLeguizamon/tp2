#include "file_reader.h"
#include "resource_generator.h"
#include "blocking_queue.h"
#include "resource.h"
#include "worker.h"
#include "thread_spawner.h"
#include "counter.h"
#include "printer.h"

//cpplint
#include <map>
#include <string>
#include <list>

int main(int argc, char const *argv[]){
    FileReader file_reader(argv[1]);

    std::map<std::string, int> workers = file_reader.getMapOfWorkers();

    file_reader.changeReadingFile(argv[2]);

    std::list<char> resources = file_reader.getResources();

    //trabajo con tod el contenido del archivo en memoria,
    // seria mejor leer caracter a caracter
/**Aca termina el file reader*/

/**El main thread spawnea a todos los demas*/

    BlockingQueue wheat_source;
    BlockingQueue wood_source;
    BlockingQueue iron_and_carbon_source;
    Storage storage;
    Counter profit_counter;

/**Los workers ya deben estar esperando por recursos antes que
 * el main thread empieze a llenar las colas*/
    Printer printer(storage, profit_counter);

    ThreadSpawner thread_spawner(workers);

    thread_spawner.spawnCooks(&storage, profit_counter);
    thread_spawner.spawnCarpenters(&storage, profit_counter);
    thread_spawner.spawnGunSmiths(&storage, profit_counter);

    thread_spawner.spawnFarmers(&wheat_source, &storage);
    thread_spawner.spawnWoodCutters(&wood_source, &storage);
    thread_spawner.spawnMiners(&iron_and_carbon_source, &storage);

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
