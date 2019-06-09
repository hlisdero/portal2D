#ifndef SAFE_QUEUE_H
#define SAFE_QUEUE_H

#include <queue>
#include <mutex>
#include <vector>

template <class T>
class SafeQueue {
public:
    void push(const T& event) {
        std::lock_guard<std::mutex> lock(mutex);
        events.push(events);
    }

    std::vector<T> popAll() {
        std::unique_lock<std::mutex> lock(mutex);

        std::vector<T> elements;
        while (!events.empty()) {
            elements.push_back(events.front());
            events.pop();
        }

        return std::move(elements);
    }

private:
    std::queue<T> events;
    std::mutex mutex;
};

#endif  // SAFE_QUEUE_H
