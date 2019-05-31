#include "server/map_loader.h"

#include <map>
#include <string>

#include "server/entities/door.h"
#include "server/entities/energy_emittor.h"
#include "server/entities/energy_receiver.h"
#include "server/entities/button.h"
#include "server/entities/rock.h"
#include "server/entities/end_barrier.h"

Map MapLoader::loadMap(const char * mapName) {
	// TODO if map exist?
	
	YAML::Node file;
	try {
		file = YAML::LoadFile(mapName);
	} catch(...) {
		throw std::runtime_error("Impossible to load the map");
	}

	Map map;

	try {
		this->loadSettings(map, file);
	} catch(...) {
		throw std::runtime_error("Impossible to load the map settings");
	}
	try {
		this->loadEntities(map, file);
	} catch(...) {
		throw std::runtime_error("Impossible to load the map entities");
	}

	return std::move(map);
}

void MapLoader::loadSettings(Map & map, YAML::Node yaml) {
	map.minPlayers = yaml["min-players"].as<int>();

	YAML::Node spawn = yaml["spawn"];
	map.spawn.x = spawn["x"].as<float>();
	map.spawn.y = spawn["y"].as<float>();
}

void MapLoader::loadEntities(Map & map, YAML::Node yaml) {
	YAML::Node entities = yaml["entities"];

	std::map<std::string, WithSubscribableState*> subscribables; 
	std::vector<DoorEntity*> doors; 

	for(uint i = 0; i < entities.size(); i++) {
		Entity * entity = this->createEntity(map, entities[i]);

		if(entity->getType() < DYNAMIC_ENTITY_START) {
			map.staticEntities.push_back(entity);
		} else {
			map.dynamicEntities.push_back(entity);
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

Entity * MapLoader::createEntity(Map & map, YAML::Node yaml) {
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
			entity = new EndBarrierEntity(yaml, map.endZone);
			break;
		case TYPE_ROCK:
			entity = new RockEntity(yaml);
			break;
		default:
			throw std::runtime_error("Unsupported entity type");
	}

	return entity;
}