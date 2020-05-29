//
// Created by agustin on 8/5/20.
//

#include "blocking_queue.h"


void BlockingQueue::push(Resource* element) {
    std::unique_lock<std::mutex> lock(m);
    this->queue.push(element);
    cond_var.notify_all();
}


Resource* BlockingQueue::pop() {
    std::unique_lock<std::mutex> lock(m);
    while (queue.empty()){
        if (this->is_close){
            throw ClosedQueueException();
        }
        cond_var.wait(lock);
    }

    Resource* resource = queue.front();
    queue.pop();

    return resource;
}

void BlockingQueue::close() {
    std::unique_lock<std::mutex> lock(m);
    this->is_close = true;
    this->cond_var.notify_all();
}

BlockingQueue::BlockingQueue() :
    is_close(false)
    {}

BlockingQueue::~BlockingQueue(){
    while (!queue.empty()) {
        delete (queue.front());
        queue.pop();
    }
}
