#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include "active_socket.h"
#include "screen.h"
#include "texture_creator.h"

class Client {
public:
    Client(const std::string& hostname,
           const std::string& port);

    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&& other) = delete;
    Client& operator=(Client&& other) = delete;

    void run();

private:
    ActiveSocket skt_;

    void greetServer();
    void runWindow1();
    void runWindow2();
};

#endif  // CLIENT_H
