#ifndef RECEIVER_THREAD_H
#define RECEIVER_THREAD_H

#include "common/protocol/abstract_thread.h"
#include "common/queue/blocking_queue.h"
#include "common/protocol/protocol.h"

template<class T>
class ReceiverThread: public AbstractThread {
public:
    ReceiverThread(Protocol& protocol, BlockingQueue<T>& queue) :
        protocol(protocol), queue(queue) {}

    virtual void run() override {
        running = true;
        try {
            while (true) {
                T event;
                protocol.receive(event);
                if (event.type == 0) {
                    return;
                }
                queue.push(event);
            }
        } catch (...) {}
        running = false;
    }

    bool is_running() const {
        return running;
    }

private:
    bool running = false;
    Protocol& protocol;
    BlockingQueue<T>& queue;
};

#endif  // RECEIVER_THREAD_H
