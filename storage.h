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
private:
    typedef enum resource_t{
        WHEAT,
        WOOD,
        IRON,
        CARBON,
    }resource_t;

    std::mutex mutex;
    std::map<resource_t, std::queue<Resource*>> inventory;
    std::condition_variable cond_var;
    bool is_close;

public:
    Storage();

    /*DoubleDispatch: Recibe un recurso y lo agrega al std::map inventory
     * notifica a todos los hilos*/
    void addResource(Wheat* wheat);

    /*DoubleDispatch: Recibe un recurso y lo agrega al std::map inventory
     * notifica a todos los hilos*/
    void addResource(Wood* wood);

    /*DoubleDispatch: Recibe un recurso y lo agrega al std::map inventory
     * notifica a todos los hilos*/
    void addResource(Iron* iron);

    /*DoubleDispatch: Recibe un recurso y lo agrega al std::map inventory
     * notifica a todos los hilos*/
    void addResource(Carbon* carbon);

    /*Recorre cada queue del map y libera la cantidad de
     * recursos que recibe por parametro*/
    void consumeResources(unsigned int wheat_qty, unsigned int wood_qty,
                          unsigned int iron_qty, unsigned int carbon_qty);

    unsigned int getWheat();

    unsigned int getWood();

    unsigned int getIron();

    unsigned int getCarbon();

    /*is_close pasa a true y notifica a todos los hilos*/
    void close();

    /*Libera todos los recursos restantes en cada queue del std::map*/
    ~Storage();
};



#endif //TP2CLION_STORAGE_H
