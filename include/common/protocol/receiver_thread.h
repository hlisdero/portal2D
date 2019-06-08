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
        while (true) {
            T event;
            protocol.receive(event);
            if (!event.type) {
                return;
            }
            queue.push(event);
        }
    }

private:
    Protocol& protocol;
    BlockingQueue<T>& queue;
};

#endif  // RECEIVER_THREAD_H
