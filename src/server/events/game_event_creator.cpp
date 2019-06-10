#include "server/events/game_event_creator.h"

GameEventCreator::GameEventCreator(SafeQueue<GameEvent>& queue) : queue(queue) {}

void GameEventCreator::addStateUpdate(Entity * entity) {
	GameEvent event(ENTITY_STATE_UPDATE, entity);
	queue.push(event);
}

void GameEventCreator::addTeleportation(Entity * entity) {
	GameEvent event(ENTITY_TELEPORT, entity);
	queue.push(event);
}

void GameEventCreator::addPortalsReset(Entity * entity) {
	GameEvent event(PORTALS_RESET, entity);
	queue.push(event);
}

void GameEventCreator::addBallDestruction(Entity * entity) {
	GameEvent event(ENERGY_BALL_DESTRUCTION, entity);
	queue.push(event);
}

void GameEventCreator::addSetActiveEntity(Entity * entity, bool active) {
	GameEvent event(entity, active);
	queue.push(event);
}

void GameEventCreator::addGameStateChange(GameStatus status) {
	GameEvent event(status);
	queue.push(event);
}

void GameEventCreator::addKillPlayer(Entity * entity) {
	GameEvent event(KILL_PLAYER, entity);
	queue.push(event);
}