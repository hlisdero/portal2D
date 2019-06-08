#include "common/protocol/protocol.h"

Protocol::Protocol(ActiveSocket skt) : skt(std::move(skt)) {}

void Protocol::send(const ViewEvent& event) {
    sendInteger<ViewEventType>(event.type);
    sendInteger<MoveDirection>(event.direction);
    sendBoolean(event.pressed);
    sendBoolean(event.repeat);
    sendClickDirection(event.click_direction);
}

void Protocol::send(const WorldEvent& event) {
    sendInteger<WorldEventType>(event.type);
    sendInteger<int>(event.id);
    sendInteger<EntityType>(event.entity_type);
    sendPosition(event.position);
    sendInteger<State>(event.state);
}

void Protocol::receive(ViewEvent& event) {
    event.type = receiveInteger<ViewEventType>();
    event.direction = receiveInteger<MoveDirection>();
    event.pressed = receiveBoolean();
    event.repeat = receiveBoolean();
    event.click_direction = receiveClickDirection();
}

void Protocol::receive(WorldEvent& event) {
    event.type = receiveInteger<WorldEventType>();
    event.id = receiveInteger<int>();
    event.entity_type = receiveInteger<EntityType>();
    event.position = receivePosition();
    event.state = receiveInteger<State>();
}

void Protocol::sendBoolean(const bool& flag) {
    uint8_t num = flag;
    skt << num;
}

void Protocol::sendClickDirection(const ClickDirection& click_direction) {
    skt << click_direction.x;
    skt << click_direction.y;
}

void Protocol::sendPosition(const Position& position) {
    skt << position.x;
    skt << position.y;
    skt << position.z;
}

bool Protocol::receiveBoolean() {
    uint8_t num;
    skt >> num;
    return (bool) num;
}

ClickDirection Protocol::receiveClickDirection() {
    ClickDirection click_direction(0, 0);
    skt >> click_direction.x;
    skt >> click_direction.y;
    return click_direction;
}

Position Protocol::receivePosition() {
    Position position(0, 0, 0);
    skt >> position.x;
    skt >> position.y;
    skt >> position.z;
    return position;
}
