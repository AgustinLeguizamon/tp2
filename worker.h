//
// Created by agustin on 8/5/20.
//

#ifndef TP2CLION_WORKER_H
#define TP2CLION_WORKER_H

#include "resource.h"
#include "blocking_queue.h"

class Storage;
class Worker{
        Storage& storage;
        BlockingQueue& assigned_source;
        bool is_working;

    public:
        Worker(BlockingQueue &assigned_source, Storage &storage);

        //Worker(const Worker& other) = delete;

        //Worker(Worker&& other);

        void collectAResource();

        void operator()();
};


#endif //TP2CLION_WORKER_H
