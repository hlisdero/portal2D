#ifndef MAP_H
#define MAP_H

#include <vector>
#include "yaml-cpp/yaml.h"

#include "common/entities/entity.h"
#include "server/end_zone.h"

class Map {
public:
	explicit Map(int minPlayers);

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> & getDynamicEntities() const;

	EndZone & getEndZone();

	~Map();

private:
	friend MapLoader;

	int minPlayers;

	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	EndZone endZone;
};

#endif  // MAP_H
