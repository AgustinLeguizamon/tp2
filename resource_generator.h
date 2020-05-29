//
// Created by agustin on 8/5/20.
//

#ifndef TP2CLION_RESOURCE_GENERATOR_H
#define TP2CLION_RESOURCE_GENERATOR_H


#include <vector>
#include <list>
#include "resource.h"
#include "blocking_queue.h"

class ResourceGenerator {
    private:
        std::list<char> &resources;
        BlockingQueue &wheat_source;
        BlockingQueue &wood_source;
        BlockingQueue &iron_and_carbon_source;

    public:
        ResourceGenerator(std::list<char> &resources,
                BlockingQueue &wheat_source,
                BlockingQueue &wood_source,
                BlockingQueue &iron_and_carbon_source);

        void run();

        bool addResourceToQueue() const;

        void freeSources();

private:
        void generateAResource(char resource_character) const;
};


#endif //TP2CLION_RESOURCE_GENERATOR_H
