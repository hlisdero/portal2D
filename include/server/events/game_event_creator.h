#ifndef GAME_EVENT_CREATOR_H
#define GAME_EVENT_CREATOR_H

#include "server/queue/safe_queue.h"
#include "server/events/game_event.h"
#include "server/entities/entity.h"

class GameEventCreator {
public:
	GameEventCreator(SafeQueue<GameEvent>& queue);

	void addStateUpdate(Entity* entity);
	void addTeleportation(Entity * entity);
	void addSetActiveEntity(Entity * entity, bool active);
	void addPortalsReset(Entity * entity);
	void addBallDestruction(Entity * entity);
	void addRockRespawn(Entity * entity);

	void addGameStateChange(GameStatus status); 

	void addPotentialVictory(size_t playerCount); 
	
	void addKillPlayer(Entity* entity); 

private:
	SafeQueue<GameEvent>& queue;
};

#endif
