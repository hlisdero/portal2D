#include "server/client_manager.h"

ClientManager::~ClientManager() {
    for (const auto& client : clients) {
        delete client;
    }
}

std::queue<WorldEvent>& ClientManager::getSendQueue() {
    return world_events;
}

std::queue<ViewEvent>& ClientManager::getReceiveQueue() {
    return view_events;
}

void ClientManager::addClient(ActiveSocket skt) {
    Interface<WorldEvent, ViewEvent>* client_interface = new Interface<WorldEvent, ViewEvent>(std::move(skt));
    clients.push_back(client_interface);
}

void ClientManager::addSelectPlayer(int client_index, int player_index) {
    checkValidIndex(client_index);
    WorldEvent event;
    event.type = SELECT_PLAYER;
    event.id = player_index;
    clients[client_index]->getSendQueue().push(event);
}

void ClientManager::joinInputQueues() {
    bool delete_flag = false;
    size_t index = clients.size();

    for (size_t i = 0; i < clients.size(); ++i) {
        std::vector<ViewEvent> events = clients[i]->getReceiveQueue().popAll();
        for (const auto& event : events) {
            view_events.push(event);
            if (event.type == QUIT) {
                delete_flag = true;
                index = i;
                break;  // Siguiente cliente
            }
        }
    }
    if (delete_flag) {
        delete clients[index];
        clients.erase(clients.begin() + index);
    }
}

void ClientManager::broadcast() {
    while (!world_events.empty()) {
        WorldEvent event = world_events.front();
        world_events.pop();
        for (const auto& client : clients) {
            client->getSendQueue().push(event);
        }
    }
}

void ClientManager::checkValidIndex(size_t index) {
    if (index >= clients.size()) {
        throw std::runtime_error("Error: Índice de cliente inválido");
    }
}
