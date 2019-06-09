#include "server/events/game_event_creator.h"

GameEventCreator::GameEventCreator(SafeQueue<GameEvent>& queue) : queue(queue) {}

void GameEventCreator::addStateUpdate(Entity * entity) {
	GameEvent event(entity);
	queue.push(event);
}

void GameEventCreator::addSetActiveEntity(Entity * entity, bool active) {
	GameEvent event(entity, active);
	queue.push(event);
}