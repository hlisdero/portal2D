#include "server/game.h"

Game::Game(MapLoader & mapLoader, const char * mapName) :
	map(mapLoader.loadMap(mapName)),
	world(this->map) {}

void Game::processEvent() {
	// if player join
	//	createPlayer
	// if playerCount > map.getRequiredPlayersCount(): status= In progress

	// if player move
	//	move player
}

void Game::addPlayer(PlayerEntity * player) {
	this->world.createPlayer(player);
}

void Game::update() {


	this->world.updatePhysics();
}

const std::vector<Entity*> & Game::getStaticEntities() const {
	return this->map.getStaticEntities();
}

const std::vector<Entity*> Game::getDynamicEntities() const {
	return this->world.getDynamicEntities();
}