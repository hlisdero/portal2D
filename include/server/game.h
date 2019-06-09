#ifndef GAME_H
#define GAME_H

#include <vector>

#include "server/map.h"
#include "server/events/event_creator.h"
#include "server/entities/player.h"
#include "server/physics/world.h"
#include "server/events/event_creator.h"
#include "server/events/game_event_creator.h"

enum GameStatus {
	WAITING_FOR_PLAYERS,
	IN_PROGRESS,
	VICTORY,
	DEFEAT
};

class Game {
public:
	Game(const char* mapName, EventCreator& eventCreator);

	void addPlayer(PlayerEntity* player);
	void createPortal(PlayerEntity& player, ClickDirection& direction);

	void update();

    const std::vector<Entity*>& getStaticEntities() const;
    const std::vector<Entity*>& getDynamicEntities() const;

	void processGameEvents();

private:
	// std::vector<Client/Player>

	GameStatus status = WAITING_FOR_PLAYERS;

	SafeQueue<GameEvent> eventsQueue;
	GameEventCreator gameEventCreator;

	Map map;
	World world;
	EventCreator& eventCreator;
};

#endif  // GAME_H
