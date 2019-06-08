#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <vector>

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
        if (is_closed) {
            return T();
        }
        T event = events.front();
        events.pop();
        return event;
    }

    // Asume que la cola está abierta siempre
    std::vector<T> popAll() {
        std::unique_lock<std::mutex> lock(events_m);
        std::vector<T> elements;
        while (!events.empty()) {
            elements.push_back(events.front());
            events.pop();
        }
        return std::move(elements);
    }

    void close() {
        std::unique_lock<std::mutex> lock(is_closed_m);
        is_closed = true;
        events_cv.notify_all();
    }

private:
    std::queue<T> events;
    std::mutex events_m;
    std::condition_variable events_cv;
    bool is_closed = false;
    std::mutex is_closed_m;
};

#endif  // BLOCKING_QUEUE_H
