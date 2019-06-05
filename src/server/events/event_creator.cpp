#include "server/events/event_creator.h"

#include "common/events/world/dynamics_update.h"
#include "common/events/world/portal_creation.h"
#include "common/events/world/portal_move.h"
#include "common/objects/entity_position.h"
#include "common/events/world_event.h"

EventCreator::EventCreator(BlockingQueue<WorldEventPtr> & eventQueue) : eventQueue(eventQueue) {}

void EventCreator::sendDynamicsUpdate(const std::vector<Entity*> entities) {
	std::vector<EntityPosition> positions;

	for(auto entity : entities) {
		positions.emplace_back(entity->getId(), entity->getX(), entity->getY(), entity->getRotationDeg());
	}

	this->eventQueue.push(WorldEventPtr(new DynamicsUpdateEvent(positions)));
}

void EventCreator::sendPortalCreation(PortalEntity * portal) {
	this->eventQueue.push(WorldEventPtr(new PortalCreationEvent(
		portal->getId(), 
		portal->getX(), portal->getY(), portal->getRotationDeg(), 
		portal->getState())));
}

void EventCreator::sendPortalMove(PortalEntity * portal) {
	this->eventQueue.push(WorldEventPtr(new PortalMoveEvent(
		portal->getId(), 
		portal->getX(), portal->getY(), portal->getRotationDeg())));
}