#ifndef SENDER_THREAD_H
#define SENDER_THREAD_H

#include "common/protocol/abstract_thread.h"
#include "common/queue/blocking_queue.h"
#include "common/protocol/protocol.h"

template<class T>
class SenderThread: public AbstractThread {
public:
    SenderThread(Protocol& protocol, BlockingQueue<T>& queue) :
        protocol(protocol), queue(queue) {}

    virtual void run() override {
        try {
            while (true) {
                T event = queue.pop();
                protocol.send(event);
                if (event.type == 0) {
                    return;
                }
            }
        } catch (...) {}
        running = false;
    }

    bool is_running() const {
        return running;
    }

private:
    bool running = true;
    Protocol& protocol;
    BlockingQueue<T>& queue;
};

#endif  // SENDER_THREAD_H
