#include "client.h"
#include <string>

Client::Client(const std::string& hostname,
               const std::string& port) :
    skt_(hostname, port) {
    // skt_.connect();
}

void Client::run() {
    // greetServer();
    World world(15, 15);
    CollisionBox& box = world.createCollisionBox(1, 1);

    for (int32 i = 0; i < 60; ++i) {
        world.update();

        b2Vec2 position = box.getPosition();
        float32 angle = box.getAngle();

        std::printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
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
