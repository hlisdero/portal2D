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

void EventManager::addHandler(WindowEventHandler* window_event_handler) {
    event_handler.add(window_event_handler);
}

void EventManager::removeHandler(KeyboardHandler* keyboard_handler) {
    event_handler.remove(keyboard_handler);
}

void EventManager::removeHandler(MouseHandler* mouse_handler) {
    event_handler.remove(mouse_handler);
}

void EventManager::removeWindowEventHandler() {
    event_handler.removeWindowEventHandler();
}

void EventManager::pollEvents() {
    event_handler.poll();
}

bool EventManager::quit() const {
    return event_handler.quit();
}
