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
    WorldEvent event(SELECT_PLAYER, player_index);
    players[client_index] = player_index;
    clients[client_index]->getSendQueue().push(event);
}

void ClientManager::joinInputQueues() {
    std::vector<size_t> delete_indexes;

    for (size_t i = 0; i < clients.size(); ++i) {
        std::vector<ViewEvent> events = clients[i]->getReceiveQueue().popAll();
        for (const auto& event : events) {
            view_events.push(event);
            if (event.type == QUIT) {
                delete_indexes.push_back(i);
                break;  // Siguiente cliente
            }
        }

        if (!(clients[i]->valid())) {
            delete_indexes.push_back(i);
            // Comunica al servidor que el cliente se desconectó
            view_events.push(ViewEvent(players.at(i), QUIT));
        }
    }
    deleteClients(delete_indexes);
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

void ClientManager::deleteClients(const std::vector<size_t>& delete_indexes) {
    for (size_t index : delete_indexes) {
        delete clients[index];
        clients.erase(clients.begin() + index);
        players.erase(index);
    }
}
