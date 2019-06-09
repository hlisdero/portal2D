#include "server/events/game_event_creator.h"

GameEventCreator::GameEventCreator(SafeQueue<GameEvent>& queue) : queue(queue) {}

void GameEventCreator::addStateUpdate(Entity * entity) {
	GameEvent event(entity);
	queue.push(event);
}