#ifndef CLIENT_H
#define CLIENT_H

#include "common/clock_loop.h"
#include "common/socket/active_socket.h"
#include "common/protocol/interface.h"
#include "common/events/world_event.h"
#include "common/events/view_event.h"
#include "client/view/world_view.h"

class Client {
public:
    Client(const std::string& hostname, const std::string& port);

    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&& other) = delete;
    Client& operator=(Client&& other) = delete;

    void run();

private:
    Interface<ViewEvent, WorldEvent> interface;
    WorldView view;
    bool quit = false;

    void processQueue();
    void processEvent(const WorldEvent& event);
    void sendQuitSignal();
};

#endif  // CLIENT_H
