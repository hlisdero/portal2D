#ifndef CLIENT_H
#define CLIENT_H

#include "client/view/world_view.h"

class Client {
public:
    Client(float32 world_width, float32 world_height);

    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&& other) = delete;
    Client& operator=(Client&& other) = delete;

    void pollEvents();
    BlockingQueue<ViewEvent>& getQueue();
    bool quit() const;

    WorldView view;
};

#endif  // CLIENT_H
