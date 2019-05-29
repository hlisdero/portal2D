#ifndef GAME_H
#define GAME_H

#include "server/world.h"
#include "server/map.h"

enum GameStatus {
	WAITING_FOR_PLAYER,
	IN_PROGRESS,
	WIN,
	LOSE
};

class Game {
public:
	Game(MapLoader & mapLoader, char * mapName);

	// void addEvent();
	void processEvent();

private:
	// std::vector<Client/Player>

	GameStatus status = WAITING_FOR_PLAYER; 
	Map map;
	World world;
	GameStatusChecker gameStatusChecker;
};

#endif  // GAME_H
