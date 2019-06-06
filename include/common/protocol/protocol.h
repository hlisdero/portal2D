#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "common/socket/active_socket.h"
#include "common/events/view_event.h"
#include "common/events/world_event.h"

class Protocol {
public:
    explicit Protocol(ActiveSocket skt);

    Protocol(const Protocol&) = delete;
    Protocol& operator=(const Protocol&) = delete;
    Protocol(Protocol&& other) = delete;
    Protocol& operator=(Protocol&& other) = delete;

    void send(const ViewEvent& event);
    void send(const WorldEvent& event);
    ViewEvent receiveViewEvent();
    WorldEvent receiveWorldEvent();

private:
    ActiveSocket skt;

    template<class T>
    void sendInteger(const T& int_var) {
        uint32_t num = static_cast<T>(int_var);
        skt << num;
    }

    template<class T>
    T receiveInteger() {
        uint32_t num;
        skt >> num;
        return static_cast<T>(num);
    }

    void sendBoolean(const bool& flag);
    void sendClickDirection(const ClickDirection& click_direction);
    void sendPosition(const Position& position);

    bool receiveBoolean();
    ClickDirection receiveClickDirection();
    Position receivePosition();
};

#endif  // PROTOCOL_H
