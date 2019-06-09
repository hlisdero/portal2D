#include "server/game.h"

Game::Game(const char* mapName, EventCreator& eventCreator) :
	map(mapName),
	world(map, eventCreator),
	eventCreator(eventCreator) {}

void Game::addPlayer(PlayerEntity* player) {
	world.createPlayer(player);

	// TODO Check in progress (enough player to play)
	if(status == WAITING_FOR_PLAYERS
		&& world.getPlayersCount() >= map.getMinPlayers()) {
		status = IN_PROGRESS;
	}
}

void Game::createPortal(PlayerEntity& player, ClickDirection& direction) {
	world.createPortal(player, direction);
}

void Game::update() {
	// Check victory
	if(map.getEndZone().getNumberOfPlayersInZone()
		>= map.getMinPlayers() - 1) {
		status = VICTORY;
	}
	// TODO Check defeat

	world.updatePhysics();
	eventCreator.addPositionUpdates(world.getDynamicEntities());
}

const std::vector<Entity*>& Game::getStaticEntities() const {
	return map.getStaticEntities();
}

const std::vector<Entity*>& Game::getDynamicEntities() const {
	return world.getDynamicEntities();
}

void Game::processEvent() {
	// if player join
	//	createPlayer
	// if playerCount > map.getRequiredPlayersCount(): status= In progress

	// if player move
	//	move player
}
