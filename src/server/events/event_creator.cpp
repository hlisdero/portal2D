#include "server/events/event_creator.h"

#include "common/events/world/dynamics_update.h"
#include "common/objects/entity_position.h"
#include "common/events/world_event.h"

EventCreator::EventCreator(BlockingQueue<WorldEventPtr> & eventQueue) : eventQueue(eventQueue) {}

void EventCreator::sendDynamicsUpdate(const std::vector<Entity*> entities) {
	std::vector<EntityPosition> positions;

	for(auto entity : entities) {
		positions.emplace_back(entity->getId(), entity->getX(), entity->getY(), entity->getRotationDeg());
	}

	WorldEventPtr event(new DynamicsUpdateEvent(positions));
	this->eventQueue.push(event);
}