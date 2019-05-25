#include "common/queue/blocking_queue.h"

void BlockingQueue::push(const ViewEvent& event) {
    std::lock_guard<std::mutex> lock(events_m);
    events.push(event);
    events_cv.notify_one();
}

ViewEvent BlockingQueue::pop() {
    std::unique_lock<std::mutex> lock(events_m);
    while (events.empty() && !is_closed) {
        events_cv.wait(lock);
    }
    if (is_closed) {
        return ViewEvent();
    }
    ViewEvent event = events.front();
    events.pop();
    is_closed_cv.notify_one();
    return event;
}

bool BlockingQueue::empty() {
    return events.empty();
}

void BlockingQueue::close() {
    std::unique_lock<std::mutex> lock(is_closed_m);
    while (!events.empty()) {
        is_closed_cv.wait(lock);
    }
    is_closed = true;
    events_cv.notify_all();
}
