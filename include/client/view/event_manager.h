#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "client/event/event_handler.h"
#include "common/queue/blocking_queue.h"
#include "common/events/view_event.h"

class EventManager {
public:
    explicit EventManager(BlockingQueue<ViewEvent>& queue);

    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;
    EventManager(EventManager&& other) = delete;
    EventManager& operator=(EventManager&& other) = delete;

    BlockingQueue<ViewEvent>& getQueue();

    void addHandler(KeyboardHandler* keyboard_handler);
    void addHandler(MouseHandler* mouse_handler);
    void addHandler(WindowEventHandler* window_event_handler);

    void removeHandler(KeyboardHandler* keyboard_handler);
    void removeHandler(MouseHandler* mouse_handler);
    void removeWindowEventHandler();

    void pollEvents();
    bool quit() const;

private:
    EventHandler event_handler;
    BlockingQueue<ViewEvent>& queue;
};

#endif  // EVENT_MANAGER_H
