#ifndef END_ZONE_H
#define END_ZONE_H

#include <unordered_set>

#include "server/entities/player.h"

class EndZone {
public:
	int getNumberOfPlayersInZone();

	void playerWentTroughBarrier(PlayerEntity * player);

private:
	std::unordered_set<PlayerEntity*> playersInZone;
};

#endif