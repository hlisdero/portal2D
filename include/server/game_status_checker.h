#ifndef GAME_STATUS_CHECKER_H
#define GAME_STATUS_CHECKER_H

#include "server/world.h"
#include "server/map.h"

class GameStatusChecker {
public:
	GameStatusChecker(EndZone & endZone);

	GameStatus get();

private:
	EndZone & endZone;
};

#endif  // GAME_STATUS_CHECKER_H
