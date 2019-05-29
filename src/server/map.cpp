#include "server/map.h"

Map::Map(Map && other) :
	minPlayers(other.minPlayers),
	spawn(other.spawn),
	staticEntities(std::move(other.staticEntities)),
	dynamicEntities(std::move(other.dynamicEntities)),
	endZone(other.endZone) {}

Map::Map() {}

const std::vector<Entity*> & Map::getStaticEntities() const {
	return this->staticEntities;
}

const std::vector<Entity*> & Map::getDynamicEntities() const {
	return this->dynamicEntities;
}

EndZone & Map::getEndZone() {
	return this->endZone;
}

b2Vec2 & Map::getSpawn() {
	return this->spawn;
}

int Map::getMinPlayers() {
	return this->minPlayers;
}


Map::~Map() {
	for(uint i = 0; i < this->staticEntities.size(); i++) {
		delete this->staticEntities[i];
	}

	for(uint i = 0; i < this->dynamicEntities.size(); i++) {
		delete this->dynamicEntities[i];
	}
}