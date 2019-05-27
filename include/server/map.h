#ifndef MAP_H
#define MAP_H

#include <vector>

#include "common/entities/entity.h"

class Map {
public:
	Map();

	std::vector<Entity*> & getStaticEntities();
	std::vector<Entity*> & getDynamicEntities();

	~Map();

private:
	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;
};

#endif  // MAP_H
