#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "common/view_event.h"

class BlockingQueue {
public:
    void push(const ViewEvent& event);

    ViewEvent pop();

    bool empty();

    void close();

private:
    std::queue<ViewEvent> events;
    std::mutex events_m;
    std::condition_variable events_cv;
    bool is_closed = false;
    std::mutex is_closed_m;
    std::condition_variable is_closed_cv;
};

#endif  // BLOCKING_QUEUE_H
