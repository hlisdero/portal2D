#include "server/map.h"

#include "server/entities/door.h"
#include "server/entities/energy_emittor.h"
#include "server/entities/energy_receiver.h"
#include "server/entities/button.h"
#include "server/entities/rock.h"
#include "server/entities/end_barrier.h"

Map::Map(int minPlayers) : minPlayers(minPlayers) {}

const std::vector<Entity*> & Map::getStaticEntities() const {
	return this->staticEntities;
}

const std::vector<Entity*> & Map::getDynamicEntities() const {
	return this->dynamicEntities;
}

EndZone & Map::getEndZone() {
	return this->endZone;
}

Map::~Map() {
	for(uint i = 0; i < this->staticEntities.size(); i++) {
		delete this->staticEntities[i];
	}

	for(uint i = 0; i < this->dynamicEntities.size(); i++) {
		delete this->dynamicEntities[i];
	}
}