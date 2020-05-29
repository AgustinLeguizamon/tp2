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

        void push(Resource* resource);

        Resource* pop();

        void close();

        void freeResources();

        ~BlockingQueue();
};



#endif //TP2CLION_BLOCKING_QUEUE_H
