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

    Interface(const Interface&) = delete;
    Interface& operator=(const Interface&) = delete;
    Interface(Interface&& other) = delete;
    Interface& operator=(Interface&& other) = delete;

    ~Interface() {
        send_queue.close();
        sender_thread->join();
        delete sender_thread;
        receive_queue.close();
        receiver_thread->join();
        delete receiver_thread;
    }

    BlockingQueue<T>& getSendQueue() {
        return send_queue;
    }

    BlockingQueue<U>& getReceiveQueue() {
        return receive_queue;
    }

    void closeWait() {
        send_queue.closeWait();
        receive_queue.closeWait();
    }

private:
    Protocol protocol;
    BlockingQueue<T> send_queue;
    BlockingQueue<U> receive_queue;
    SenderThread<T>* sender_thread = nullptr;
    ReceiverThread<U>* receiver_thread = nullptr;
};

#endif  // INTERFACE_H
