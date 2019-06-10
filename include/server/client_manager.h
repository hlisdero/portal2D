#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <vector>
#include <queue>
#include "common/protocol/interface.h"
#include "common/events/view_event.h"
#include "common/events/world_event.h"

class ClientManager {
public:
    explicit ClientManager() = default;

    ClientManager(const ClientManager&) = delete;
    ClientManager& operator=(const ClientManager&) = delete;
    ClientManager(ClientManager&& other) = delete;
    ClientManager& operator=(ClientManager&& other) = delete;

    ~ClientManager();

    std::queue<WorldEvent>& getSendQueue();
    std::queue<ViewEvent>& getReceiveQueue();

    void addClient(ActiveSocket skt);
    void addSelectPlayer(int client_index, int player_index);

    void joinInputQueues();
    void broadcast();

private:
    std::vector<Interface<WorldEvent,ViewEvent>*> clients;
    std::queue<WorldEvent> world_events;
    std::queue<ViewEvent> view_events;

    void checkValidIndex(size_t index);
};

#endif  // CLIENT_MANAGER_H
