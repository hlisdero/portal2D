#ifndef MAP_H
#define MAP_H

#include <vector>

class Map;

#include "common/entities/entity.h"
#include "server/end_zone.h"
#include "server/map_loader.h"

class Map {
public:
	Map(Map & other) = default;
	Map(Map && other);

	explicit Map(int minPlayers);

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> & getDynamicEntities() const;

	EndZone & getEndZone();
	int getMinPlayers();

	~Map();

private:
	friend MapLoader;

	int minPlayers;

	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	EndZone endZone;
};

#endif  // MAP_H
