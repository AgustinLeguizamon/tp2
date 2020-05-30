//
// Created by agustin on 8/5/20.
//

#include "resource_generator.h"


ResourceGenerator::ResourceGenerator(FileReader& file_reader,
        BlockingQueue &wheat_source, BlockingQueue &wood_source,
        BlockingQueue &iron_and_carbon_source) :
    file_reader(file_reader),
    wheat_source(wheat_source),
    wood_source(wood_source),
    iron_and_carbon_source(iron_and_carbon_source)
    {}


char ResourceGenerator::addResourceToQueue() const {
    char c_resource = file_reader.getResource();
    if (c_resource != EOF){
        this->generateAResource(c_resource);
    }

    return c_resource;
}

void ResourceGenerator::generateAResource(char c_resource) const {
    switch (c_resource){
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
            throw InvalidMapCharacterException();
    }
}

void ResourceGenerator::run() {
    char is_end_of_file;
    do{
         is_end_of_file = this->addResourceToQueue();
    } while (is_end_of_file != EOF);
    //cuando se vacien los recursos del mapa le digo a las queue
    // que no se van a llenar mas
    wheat_source.close();
    wood_source.close();
    iron_and_carbon_source.close();
}

ResourceGenerator::~ResourceGenerator() = default;

