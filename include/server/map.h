#ifndef MAP_H
#define MAP_H

#include "Box2D/Box2D.h"

#include <vector>

#include "yaml-cpp/yaml.h"
#include "common/entities/entity.h"
#include "server/end_zone.h"
#include "server/door_logica.h"

class Map {
public:
	Map(const char * mapName);

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> & getDynamicEntities() const;

	EndZone & getEndZone();
	b2Vec2 & getSpawn();
	int getMinPlayers();

	~Map();

private:
	int minPlayers;
	b2Vec2 spawn;

	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	EndZone endZone;

	void loadSettings(YAML::Node yaml);
	void loadEntities(YAML::Node yaml);
	Entity * createEntity(YAML::Node yaml);
};

#endif  // MAP_H
