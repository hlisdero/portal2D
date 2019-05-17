#include "client.h"
#include <string>

Client::Client(const std::string& hostname,
               const std::string& port) :
    skt_(hostname, port) {
    // skt_.connect();
}

void Client::run() {
    // greetServer();
}

void Client::greetServer() {
    std::string message("Hola servidor!");
    skt_ << (uint32_t) 0;
    skt_ << (uint32_t) message.length();
    skt_ << message;

    uint32_t length;
    std::string response;
    skt_ >> length;
    skt_.receive(response, length);

    std::cout << response << std::endl;
}
