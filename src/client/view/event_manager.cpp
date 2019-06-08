#include "client/view/event_manager.h"

EventManager::EventManager(BlockingQueue<ViewEvent>& queue) :
    queue(queue) {}

BlockingQueue<ViewEvent>& EventManager::getQueue() {
    return queue;
}

void EventManager::addHandler(KeyboardHandler* keyboard_handler) {
    event_handler.add(keyboard_handler);
}

void EventManager::addHandler(MouseHandler* mouse_handler) {
    event_handler.add(mouse_handler);
}

void EventManager::pollEvents() {
    event_handler.poll();
}

bool EventManager::quit() const {
    return event_handler.quit();
}
