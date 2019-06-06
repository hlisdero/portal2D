#ifndef CLIENT_H
#define CLIENT_H

#include <stdexcept>
#include "client/view/world_view.h"
#include "common/events/world_event.h"
#include "common/events/view_event.h"

class Client {
public:
    Client(float32 world_width, float32 world_height);

    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&& other) = delete;
    Client& operator=(Client&& other) = delete;

    void createInitialView(BlockingQueue<WorldEvent>& queue);
    void processQueue(BlockingQueue<WorldEvent>& queue);

    void pollEvents();
    BlockingQueue<ViewEvent>& getQueue();
    bool quit() const;

private:
    WorldView view;
};

#endif  // CLIENT_H
