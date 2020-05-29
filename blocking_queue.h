//
// Created by agustin on 8/5/20.
//

#ifndef TP2CLION_BLOCKING_QUEUE_H
#define TP2CLION_BLOCKING_QUEUE_H

#include <mutex>
#include <queue>
#include <condition_variable>
#include "resource.h"

class ClosedQueueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Queue is Closed";
    }
};

class BlockingQueue {
    private:
        std::mutex m;
        std::queue<Resource*> queue;
        std::condition_variable cond_var;
        bool is_close;

    public:
        BlockingQueue();

        BlockingQueue(const BlockingQueue& other) = delete;

        /*Agrega @param resource a la queue y notifica a todos los hilos*/
        void push(Resource* resource);

        /*Remueve y devuelve el primer elemento de la queue
         * Si la queue esta vacia, pone en espera al hilo*/
        Resource* pop();

        /*is_close pasa a ser false y notifica a todos los hilos*/
        void close();

        ~BlockingQueue();
};



#endif //TP2CLION_BLOCKING_QUEUE_H
