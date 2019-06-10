#include "server/physics/end_zone.h"

EndZone::EndZone(GameEventCreator & gameEventCreator) : gameEventCreator(gameEventCreator) {}

void EndZone::setNumberOfPlayersForVictory(size_t newPlayersForVictory) {
	playersForVictory = newPlayersForVictory;
}

void EndZone::playerWentTroughBarrier(PlayerEntity * player) {
	auto iterator = this->playersInZone.insert(player);

	// If element already in list
	if(!iterator.second) {
		this->playersInZone.erase(iterator.first);
	}

	if(playersInZone.size() >= playersForVictory) {
		gameEventCreator.addGameStateChange(VICTORY);
	}
}