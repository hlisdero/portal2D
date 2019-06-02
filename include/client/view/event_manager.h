#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "client/event/event_handler.h"
#include "common/queue/blocking_queue.h"

class EventManager {
public:
    explicit EventManager() = default;

    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    EventManager(EventManager&& other) = delete;
    EventManager& operator=(EventManager&& other) = delete;

    BlockingQueue& getQueue();

    void addHandler(KeyboardHandler* keyboard_handler);
    void addHandler(MouseHandler* mouse_handler);

    void pollEvents();
    bool quit() const;

private:
    EventHandler event_handler;
    BlockingQueue queue;
};

#endif  // EVENT_MANAGER_H
