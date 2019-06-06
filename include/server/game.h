#ifndef GAME_H
#define GAME_H

#include <vector>

#include "server/map.h"
#include "server/events/event_creator.h"
#include "server/entities/player.h"
#include "server/physics/world.h"

enum GameStatus {
	WAITING_FOR_PLAYERS,
	IN_PROGRESS,
	VICTORY,
	DEFEAT
};

class Game {
public:
	Game(const char * mapName, EventCreator & eventCreator);

	void addPlayer(PlayerEntity * player);
	void createPortal(PlayerEntity & player, b2Vec2 & direction);

	void update();

	// void addEvent();
	void processEvent();

private:
	// std::vector<Client/Player>

	GameStatus status = WAITING_FOR_PLAYERS;
	Map map;
	World world;
	EventCreator & eventCreator;
};

#endif  // GAME_H
