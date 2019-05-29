#include "server/end_zone.h"

int EndZone::getNumberOfPlayersInZone() {
	return this->playersInZone.size();
}

void EndZone::playerWentTroughBarrier(PlayerEntity * player) {
	auto iterator = this->playersInZone.insert(player);

	// If element already in list
	if(!iterator.second) {
		this->playersInZone.erase(iterator.first);
	}
}