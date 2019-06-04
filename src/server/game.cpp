#include "server/game.h"

Game::Game(const char * mapName, EventCreator & eventCreator) :
	map(mapName),
	world(this->map),
	eventCreator(eventCreator) {}

void Game::processEvent() {
	// if player join
	//	createPlayer
	// if playerCount > map.getRequiredPlayersCount(): status= In progress

	// if player move
	//	move player
}

void Game::addPlayer(PlayerEntity * player) {
	this->world.createPlayer(player);

	// TODO Check in progress (enough player to play)
	if(this->status == WAITING_FOR_PLAYERS
		&& this->world.getPlayersCount() >= this->map.getMinPlayers()) {
		this->status = IN_PROGRESS;
	}

}

void Game::createPortal(PlayerEntity & player, b2Vec2 & direction, PortalColor color) {
	this->world.createPortal(player, direction, color);
}

void Game::update() {
	// Check victory
	if(this->map.getEndZone().getNumberOfPlayersInZone() 
		>= this->map.getMinPlayers() - 1) {
		this->status = VICTORY;
	}
	// TODO Check defeat

	this->world.updatePhysics();
	this->eventCreator.sendDynamicsUpdate(
		this->world.getDynamicEntities());
}

const std::vector<Entity*> & Game::getStaticEntities() const {
	return this->map.getStaticEntities();
}

const std::vector<Entity*> Game::getDynamicEntities() const {
	return std::move(this->world.getDynamicEntities());
}