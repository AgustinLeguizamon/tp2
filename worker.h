//
// Created by agustin on 8/5/20.
//

#ifndef TP2CLION_WORKER_H
#define TP2CLION_WORKER_H

#include <vector>
#include <queue>
#include "resource.h"
#include "blocking_queue.h"
#include "storage.h"

class Worker{
        Storage* storage;
        BlockingQueue* assigned_source;
        bool is_working;

    public:
        Worker(BlockingQueue* assigned_source, Storage* storage);

        void collectAResource();

        void operator()();
};


#endif //TP2CLION_WORKER_H
