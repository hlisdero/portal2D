#include "server/map.h"

#include <map>
#include <string>

#include "server/entities/door.h"
#include "server/entities/energy_emittor.h"
#include "server/entities/energy_receiver.h"
#include "server/entities/button.h"
#include "server/entities/rock.h"
#include "server/entities/end_barrier.h"

Map::Map(const char * mapName) {
	YAML::Node file;
	
	try {
		file = YAML::LoadFile(mapName);
	} catch(...) {
		throw std::runtime_error("Impossible to load the map");
	}

	try {
		this->loadSettings(file);
	} catch(...) {
		throw std::runtime_error("Impossible to load the map settings");
	}

	try {
		this->loadEntities(file);
	} catch(...) {
		throw std::runtime_error("Impossible to load the map entities");
	}
}

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

void Map::loadSettings(YAML::Node yaml) {
	this->minPlayers = yaml["min-players"].as<int>();

	YAML::Node spawn = yaml["spawn"];
	this->spawn.x = spawn["x"].as<float>();
	this->spawn.y = spawn["y"].as<float>();
}

void Map::loadEntities(YAML::Node yaml) {
	YAML::Node entities = yaml["entities"];

	std::map<std::string, WithSubscribableState*> subscribables; 
	std::vector<DoorEntity*> doors; 

	for(uint i = 0; i < entities.size(); i++) {
		Entity * entity = this->createEntity(entities[i]);

		if(entity->getType() < DYNAMIC_ENTITY_START) {
			this->staticEntities.push_back(entity);
		} else {
			this->dynamicEntities.push_back(entity);
		}

		if(entity->getType() == TYPE_BUTTON ||
			entity->getType() == TYPE_ENERGY_RECEIVER) {
			std::string entityName = entities[i]["name"].as<std::string>();

			if(entity->getType() == TYPE_BUTTON) {
				subscribables[entityName] = entity->as<ButtonEntity>();
			} else {
				subscribables[entityName] = entity->as<EnergyReceiverEntity>();
			}
		}

		if(entity->getType() == TYPE_GATE) {
			doors.push_back(entity->as<DoorEntity>());
		}
	}

	for(DoorEntity * door : doors) {
		door->attach(subscribables);
	}
}

Entity * Map::createEntity(YAML::Node yaml) {
	EntityType type = static_cast<EntityType>(yaml["type"].as<int>());

	Entity * entity = nullptr;

	switch(type) {
		case TYPE_STONE_BLOCK:
		case TYPE_METAL_BLOCK:
		case TYPE_METAL_DIAG_BLOCK:
		case TYPE_ACID:
		case TYPE_ENERGY_BAR:
			entity = new Entity(type, yaml);
			break;
		case TYPE_GATE:
			entity = new DoorEntity(yaml);
			break;
		case TYPE_ENERGY_EMITTER:
			entity = new EnergyEmittorEntity(yaml);
			break;
		case TYPE_ENERGY_RECEIVER:
			entity = new EnergyReceiverEntity(yaml);
			break;
		case TYPE_BUTTON:
			entity = new ButtonEntity(yaml);
			break;
		case TYPE_END_BARRIER:
			entity = new EndBarrierEntity(yaml, this->endZone);
			break;
		case TYPE_ROCK:
			entity = new RockEntity(yaml);
			break;
		default:
			throw std::runtime_error("Unsupported entity type");
	}

	return entity;
}

Map::~Map() {
	for(uint i = 0; i < this->staticEntities.size(); i++) {
		delete this->staticEntities[i];
	}

	for(uint i = 0; i < this->dynamicEntities.size(); i++) {
		delete this->dynamicEntities[i];
	}
}