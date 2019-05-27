#include "server/map.h"

#include "server/entities/rock.h"

Map::Map() {
	this->staticEntities.push_back(new Entity(TYPE_METAL_BLOCK, 1.0f, 1.0f, 0.0f));
	this->staticEntities.push_back(new Entity(TYPE_METAL_BLOCK, 2.0f, 1.0f, 0.0f));
	this->staticEntities.push_back(new Entity(TYPE_METAL_BLOCK, 3.0f, 1.0f, 0.0f));
	this->dynamicEntities.push_back(new RockEntity(1.0f, 5.0f));
}

std::vector<Entity*> & Map::getStaticEntities() {
	return this->staticEntities;
}

std::vector<Entity*> & Map::getDynamicEntities() {
	return this->dynamicEntities;
}

Map::~Map() {
	for(uint i = 0; i < this->staticEntities.size(); i++) {
		delete staticEntities[i];
	}

	for(uint i = 0; i < this->dynamicEntities.size(); i++) {
		delete dynamicEntities[i];
	}
}