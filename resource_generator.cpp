//
// Created by agustin on 8/5/20.
//

#include "resource_generator.h"
//cpplint
#include <list>

ResourceGenerator::ResourceGenerator(std::list<char> &resources,
        BlockingQueue &wheat_source, BlockingQueue &wood_source,
        BlockingQueue &iron_and_carbon_source) :
    resources(resources),
    wheat_source(wheat_source),
    wood_source(wood_source),
    iron_and_carbon_source(iron_and_carbon_source)
    {}


bool ResourceGenerator::addResourceToQueue() {
    bool is_empty = resources.empty();

    if (!is_empty){
        char resource_character = this->resources.front();
        resources.pop_front();
        this->generateAResource(resource_character);
    }

    return is_empty;
}

void ResourceGenerator::generateAResource(char resource_character) {
    switch (resource_character){
        case 'T':
            this->wheat_source.push(new Wheat());
            break;
        case 'M':
            this->wood_source.push(new Wood());
            break;
        case 'C':
            this->iron_and_carbon_source.push(new Carbon());
            break;
        case 'H':
            this->iron_and_carbon_source.push(new Iron());
            break;
        default:
            //throw(CharacterIsNotAResourceException)
            break;
    }
}

void ResourceGenerator::run() {
    bool is_empty;
    do {
        is_empty = this->addResourceToQueue();
    } while (!is_empty);
    //cuando se vacien los recursos del mapa le digo a las queue
    // que no se van a llenar mas
    wheat_source.close();
    wood_source.close();
    iron_and_carbon_source.close();
}

void ResourceGenerator::freeSources() {
    wheat_source.freeResources();
    wood_source.freeResources();
    iron_and_carbon_source.freeResources();
}
