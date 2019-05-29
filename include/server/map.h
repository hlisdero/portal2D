#ifndef MAP_H
#define MAP_H

#include "Box2D/Box2D.h"

#include <vector>

class Map;

#include "common/entities/entity.h"
#include "server/end_zone.h"
#include "server/map_loader.h"

class Map {
public:
	Map(Map & other) = default;
	Map(Map && other);

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> & getDynamicEntities() const;

	EndZone & getEndZone();
	int getMinPlayers();

	~Map();

private:
	friend MapLoader;

	int minPlayers = 0;
	b2Vec2 spawn;

	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	EndZone endZone;

	Map();
};

#endif  // MAP_H
