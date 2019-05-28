#ifndef CLIENT_H
#define CLIENT_H

#include "client/event/event_handler.h"
#include "client/view/world_view.h"
#include "client/view/input_handler.h"
#include "common/queue/blocking_queue.h"

class Client {
public:
    explicit Client();

    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&& other) = delete;
    Client& operator=(Client&& other) = delete;

    void pollEvents();

    WorldView view;
    BlockingQueue queue;

private:
    EventHandler event_handler;
    InputHandler input_handler;
};

#endif  // CLIENT_H
