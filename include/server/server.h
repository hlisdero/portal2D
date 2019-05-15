#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include "passive_socket.h"

class Server {
public:
    Server(const std::string& port);

    explicit Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    explicit Server(Server&& other) = delete;
    Server& operator=(Server&& other) = delete;

    void run();

private:
    PassiveSocket passive_skt_;
};

#endif  // SERVER_H
