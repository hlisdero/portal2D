#include "server.h"
#include <string>

Server::Server(const std::string& port) :
    passive_skt_(port) {
    passive_skt_.bind();
    passive_skt_.listen();
}

void Server::run() {
    ActiveSocket client_skt = passive_skt_.accept();

    uint32_t command;
    uint32_t length;
    std::string message;
    client_skt >> command;
    client_skt >> length;
    client_skt.receive(message, length);

    std::cout << command << std::endl;
    std::cout << message << std::endl;

    std::string response("Hola cliente!");
    client_skt << (uint32_t) response.length();
    client_skt << response;
}
