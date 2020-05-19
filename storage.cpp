//
// Created by agustin on 9/5/20.
//

#include "storage.h"

Storage::Storage() :
    is_close(false)
    {}

void Storage::addResource(Wheat* wheat) {
    std::unique_lock<std::mutex> lock(mutex);
    inventory[WHEAT].push(wheat);
    cond_var.notify_all();
}

void Storage::addResource(Wood *wood) {
    std::unique_lock<std::mutex> lock(mutex);
    inventory[WOOD].push(wood);
    cond_var.notify_all();
}

void Storage::addResource(Iron *iron) {
    std::unique_lock<std::mutex> lock(mutex);
    inventory[IRON].push(iron);
    cond_var.notify_all();
}

void Storage::addResource(Carbon *carbon) {
    std::unique_lock<std::mutex> lock(mutex);
    inventory[CARBON].push(carbon);
    cond_var.notify_all();
}

void Storage::close() {
    std::unique_lock<std::mutex> lock(mutex);
    this->is_close = true;
    this->cond_var.notify_all();
}


void Storage::consumeResources(const unsigned int wheat_qty,
        const unsigned int wood_qty,
        const unsigned int iron_qty, const unsigned int carbon_qty) {
    std::unique_lock<std::mutex> lock(mutex);
    while (inventory[WHEAT].size() < wheat_qty ||
        inventory[WOOD].size() < wood_qty ||
        inventory[IRON].size() < iron_qty ||
        inventory[CARBON].size() < carbon_qty){
        if (this->is_close){
            throw ClosedStorageException();
        }
        cond_var.wait(lock);
    }

    for (unsigned int i = 0; i < wheat_qty; ++i) {
        delete(inventory[WHEAT].front());
        inventory[WHEAT].pop();
    }
    for (unsigned int j = 0; j < wood_qty; ++j) {
        delete(inventory[WOOD].front());
        inventory[WOOD].pop();
    }
    for (unsigned int k = 0; k < iron_qty; ++k) {
        delete(inventory[IRON].front());
        inventory[IRON].pop();
    }
    for (unsigned int l = 0; l < carbon_qty; ++l) {
        delete(inventory[CARBON].front());
        inventory[CARBON].pop();
    }
}

unsigned  int Storage::getWheat(){
    return inventory[WHEAT].size();
}

unsigned  int Storage::getWood(){
    return inventory[WOOD].size();
}

unsigned  int Storage::getIron(){
    return inventory[IRON].size();
}

unsigned  int Storage::getCarbon(){
    return inventory[CARBON].size();
}

Storage::~Storage(){
    //libera todos los recursos restantes en el inventario
    for (auto & resources : inventory){
        while (!resources.second.empty()){
            delete(resources.second.front());
            resources.second.pop();
        }
    }
}

