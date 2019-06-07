#ifndef INTERFACE_H
#define INTERFACE_H

#include "common/socket/active_socket.h"
#include "common/queue/blocking_queue.h"
#include "common/protocol/protocol.h"
#include "common/protocol/receiver_thread.h"
#include "common/protocol/sender_thread.h"

// T: clase que envía
// U: clase que recibe
template<class T, class U>
class Interface {
public:
    Interface(ActiveSocket skt) :
        protocol(std::move(skt)) {
        sender_thread = new SenderThread<T>(protocol, send_queue);
        receiver_thread = new ReceiverThread<U>(protocol, receive_queue);
        sender_thread->start();
        receiver_thread->start();
    }

    ~Interface() {
        send_queue.close();
        receive_queue.close();
        sender_thread->join();
        delete sender_thread;
        receiver_thread->join();
        delete receiver_thread;
    }

    Interface(const Interface&) = delete;
    Interface& operator=(const Interface&) = delete;
    Interface(Interface&& other) = delete;
    Interface& operator=(Interface&& other) = delete;

    BlockingQueue<T> send_queue;
    BlockingQueue<U> receive_queue;

private:
    Protocol protocol;
    SenderThread<T>* sender_thread = nullptr;
    ReceiverThread<U>* receiver_thread = nullptr;
};

#endif  // INTERFACE_H
