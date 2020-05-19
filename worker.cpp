//
// Created by agustin on 8/5/20.
//

#include <unistd.h>
#include "worker.h"

#define MS_PRODUCER_SLEEP 50000

void Worker::collectAResource() {
    try {
        Resource* resource = assigned_source->pop(); //recolecto
        unsigned int micro_seconds = MS_PRODUCER_SLEEP;
        usleep(micro_seconds);//duermo
        resource->addYourselfTo(this->storage);//deposito
    } catch(ClosedQueueException& e){
        this->is_working = false;
    }
}

Worker::Worker(BlockingQueue* assigned_source, Storage* storage) :
    storage(storage),
    assigned_source(assigned_source),
    is_working(true)
    {}

void Worker::operator()() {
    while (is_working){
        this->collectAResource();
    }
}
