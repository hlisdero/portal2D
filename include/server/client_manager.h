#ifndef CLIENT_MANAGER_H
#define CLIENT_MANAGER_H

#include <vector>
#include <queue>
#include <unordered_map>
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
    // Guarda el índice de jugador asociado a cada cliente
    std::unordered_map<size_t, size_t> players;

    void checkValidIndex(size_t index);
    void deleteClients(const std::vector<size_t>& delete_indexes);
};

#endif  // CLIENT_MANAGER_H
