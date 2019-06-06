#include "server/events/event_creator.h"

EventCreator::EventCreator(BlockingQueue<WorldEvent>& queue) : queue(queue) {}

void EventCreator::addEntityCreation(Entity* entity) {
    Position position(entity->getX(), entity->getY(), entity->getRotationDeg());
    WorldEvent event(entity->getId(), entity->getType(), position);
    queue.push(event);
}

void EventCreator::addPositionUpdate(Entity* entity) {
    Position position(entity->getX(), entity->getY(), entity->getRotationDeg());
    WorldEvent event(entity->getId(), position);
    queue.push(event);
}

void EventCreator::addButtonStateUpdate(ButtonEntity* entity) {
    State state;
    if (entity->getState()) {
        state = STATE_DISABLED;
    } else {
        state = STATE_ENABLED;
    }
    WorldEvent event(entity->getId(), state);
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

void EventCreator::addPortalCreation(PortalEntity * portal) {
    Position position(portal->getX(), portal->getY(), portal->getRotationDeg());
    WorldEvent event(portal->getId(), TYPE_PORTAL, position);
	queue.push(event);
}

void EventCreator::addPortalMove(PortalEntity * portal) {
    Position position(portal->getX(), portal->getY(), portal->getRotationDeg());
    WorldEvent event(portal->getId(), position);
	queue.push(event);
}
