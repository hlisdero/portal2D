#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include "server/map.h"

class MapLoader {
public:
	Map loadMap(char * mapName);

private:
	void loadEntities(Map & map, YAML::Node yaml);
	Entity * createEntity(YAML::Node yaml);
};

#endif  // MAP_LOADER_H
