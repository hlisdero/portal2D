#ifndef END_ZONE_H
#define END_ZONE_H

#include <unordered_set>

#include "server/entities/player.h"
#include "server/events/game_event_creator.h"

class EndZone {
public:
	EndZone(GameEventCreator & gameEventCreator);

	void setNumberOfPlayersForVictory(size_t playersForVictory);

	void playerWentTroughBarrier(PlayerEntity * player);

private:
	size_t minPlayersForVictory = 1;
	std::unordered_set<PlayerEntity*> playersInZone;
	GameEventCreator & gameEventCreator;
};

#endif