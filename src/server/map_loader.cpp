#include "server/map_loader.h"

Map MapLoader::loadMap(char * mapName) {
	// TODO if map exist?
	
	YAML::Node file = YAML::LoadFile("../data/maps/map1.yaml");

	int minPlayers = yaml["min-players"].as<int>();

	Map map(minPlayers);
	this->loadEntities(map, file);

	return map;
}

void MapLoader::loadEntities(Map & map, YAML::Node yaml) {
	YAML::Node entities = yaml["entities"];

	for(uint i = 0; i < entities.size(); i++) {
		Entity * entity = this->createEntity(map, entities[i]);

		if(entity->getType() < DYNAMIC_ENTITY_START) {
			map.staticEntities.push_back(entity);
		} else {
			map.dynamicEntities.push_back(entity);
		}
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
		case TYPE_DOOR:
			entity = new DoorEntity(yaml);
			break;
		case TYPE_ENERGY_EMITTOR:
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