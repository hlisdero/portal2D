#ifndef ABSTRACT_THREAD_H
#define ABSTRACT_THREAD_H

#include <thread>

class AbstractThread {
public:
    AbstractThread() = default;

    AbstractThread(const AbstractThread&) = delete;
    AbstractThread& operator=(const AbstractThread&) = delete;

    AbstractThread(AbstractThread&& other);
    AbstractThread& operator=(AbstractThread&& other);

    virtual ~AbstractThread() = default;

    void start();
    void join();

    virtual void run() = 0;

private:
    std::thread thread_;
};

#endif  // ABSTRACT_THREAD_H
