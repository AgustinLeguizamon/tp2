//
// Created by agustin on 8/5/20.
//

#ifndef TP2CLION_RESOURCE_GENERATOR_H
#define TP2CLION_RESOURCE_GENERATOR_H


#include "blocking_queue.h"
#include "file_reader.h"

class Resource;
class ResourceGenerator {
    private:
        FileReader &file_reader;
        BlockingQueue &wheat_source;
        BlockingQueue &wood_source;
        BlockingQueue &iron_and_carbon_source;

    public:
        ResourceGenerator(FileReader& file_reader,
                BlockingQueue &wheat_source,
                BlockingQueue &wood_source,
                BlockingQueue &iron_and_carbon_source);

        /*Llama a addResourceToQueue hasta vaciar la lista de recursos y
         * luego cierra cada queue.*/
        void run();

        ~ResourceGenerator();

    private:
        /*Obtiene el siguiente caracter del mapa de recursos y lo agrega a la BlockingQueue
         * del tipo correspondiente*/
        char addResourceToQueue() const;

        /*Reserva en el heap un nuevo recurso (Resource) del tipo indicado
         * por @param c_resource*/
        void generateAResource(char c_resource) const;
};


#endif //TP2CLION_RESOURCE_GENERATOR_H
