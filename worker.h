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

        Worker(const Worker& other) = delete;

        Worker(Worker&& other) noexcept;

        /*Quita un recurso de assigned_source, duerme el hilo por 50ms y los
         * deposita en storage*/
        void collectAResource();

        /*Llama a collectAResource mientras is_working = true*/
        void operator()();
};


#endif //TP2CLION_WORKER_H
