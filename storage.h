//
// Created by agustin on 9/5/20.
//

#ifndef TP2CLION_STORAGE_H
#define TP2CLION_STORAGE_H


#include <map>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "resource.h"

class ClosedStorageException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Storage is Closed";
    }
};


class Producer;

class Storage {
public:
    typedef enum resource_t{
        WHEAT,
        WOOD,
        IRON,
        CARBON,
    }resource_t;

private:
    std::mutex mutex;
    std::map<resource_t, std::queue<Resource*> > inventory;
    std::condition_variable cond_var;
    bool is_close;

public:
    Storage();

    void addResource(Wheat* wheat);

    void addResource(Wood* wood);

    void addResource(Iron* iron);

    void addResource(Carbon* carbon);

    void consumeResources(unsigned int wheat_qty, unsigned int wood_qty,
                          unsigned int iron_qty, unsigned int carbon_qty);

    unsigned int freeRemainingResource(resource_t resource);

    void close();

    ~Storage();
};



#endif //TP2CLION_STORAGE_H
