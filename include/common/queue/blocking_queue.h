#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <class T>
class BlockingQueue {
public:
    void push(const T& event) {
        std::lock_guard<std::mutex> lock(events_m);
        events.push(event);
        events_cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(events_m);
        while (events.empty() && !is_closed) {
            events_cv.wait(lock);
        }
        T event = events.front();
        events.pop();
        is_closed_cv.notify_one();
        return event;
    }

    bool empty() {
        return events.empty();
    }

    void close() {
        std::unique_lock<std::mutex> lock(is_closed_m);
        while (!events.empty()) {
            is_closed_cv.wait(lock);
        }
        is_closed = true;
        events_cv.notify_all();
    }

private:
    std::queue<T> events;
    std::mutex events_m;
    std::condition_variable events_cv;
    bool is_closed = false;
    std::mutex is_closed_m;
    std::condition_variable is_closed_cv;
};

#endif  // BLOCKING_QUEUE_H
