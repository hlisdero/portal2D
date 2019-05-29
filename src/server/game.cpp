#include "server/game.h"

Game::Game(MapLoader & mapLoader, char * mapName) :
	map(mapLoader(mapName)),
	world(map),
	gameStatusChecker(map.getEndZone()) {}

void Game::processEvent() {
	// if player join
	//	createPlayer
	// if playerCount > map.getRequiredPlayersCount(): status= In progress

	// if player move
	//	move player
}