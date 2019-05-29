#ifndef GAME_H
#define GAME_H

#include <vector>

#include "server/world.h"
#include "server/map.h"
#include "server/entities/player.h"

enum GameStatus {
	WAITING_FOR_PLAYER,
	IN_PROGRESS,
	WIN,
	LOSE
};

class Game {
public:
	Game(MapLoader & mapLoader, const char * mapName);

	void addPlayer(PlayerEntity * player);

	void update();

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> getDynamicEntities() const;

	// void addEvent();
	void processEvent();

private:
	// std::vector<Client/Player>

	GameStatus status = WAITING_FOR_PLAYER; 
	Map map;
	World world;
};

#endif  // GAME_H
