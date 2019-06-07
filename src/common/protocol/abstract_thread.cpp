#include "common/protocol/abstract_thread.h"

AbstractThread::AbstractThread(AbstractThread&& other) {
    this->thread_ = std::move(other.thread_);
}

AbstractThread& AbstractThread::operator=(AbstractThread&& other) {
    this->thread_ = std::move(other.thread_);
    return *this;
}

void AbstractThread::start() {
    thread_ = std::thread(&AbstractThread::run, this);
}

void AbstractThread::join() {
    thread_.join();
}
