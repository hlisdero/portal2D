#ifndef MAP_H
#define MAP_H

#include <vector>
#include "yaml-cpp/yaml.h"

#include "common/entities/entity.h"
#include "server/end_zone.h"

class Map {
public:
	Map();

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> & getDynamicEntities() const;

	~Map();

private:
	int minPlayers = 1;

	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	EndZone endZone;

	void loadEntities(YAML::Node yaml);
	void loadSettings(YAML::Node yaml);
	Entity * createEntity(YAML::Node yaml);
};

#endif  // MAP_H
