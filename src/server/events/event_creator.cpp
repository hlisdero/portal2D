#include "server/events/event_creator.h"

EventCreator::EventCreator(std::queue<WorldEvent>& queue) : queue(queue) {}

void EventCreator::addEntityCreation(Entity* entity) {
    Position position(entity->getX(), entity->getY(), entity->getRotationDeg());
    WorldEvent event(entity->getId(), entity->getType(), position);
    queue.push(event);
}

void EventCreator::addEntityDestruction(Entity* entity) {
    WorldEvent event(entity->getId());
    queue.push(event);
}

void EventCreator::addPositionUpdate(Entity* entity) {
    Position position(entity->getX(), entity->getY(), entity->getRotationDeg());
    WorldEvent event(entity->getId(), position);
    queue.push(event);
}

void EventCreator::addStateUpdate(Entity* entity) {
    WorldEvent event(entity->getId(), entity->as<WithState>()->getState());
    queue.push(event);
}

void EventCreator::addEntityCreations(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        addEntityCreation(entity);
    }
}

void EventCreator::addPositionUpdates(const std::vector<Entity*>& entities) {
    for (const auto& entity : entities) {
        addPositionUpdate(entity);
    }
}
