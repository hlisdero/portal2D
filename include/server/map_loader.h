#ifndef MAP_LOADER_H
#define MAP_LOADER_H

class MapLoader;

#include "yaml-cpp/yaml.h"
#include "server/map.h"
#include "server/door_logica.h"

class MapLoader {
public:
	Map loadMap(const char * mapName);

private:
	void loadSettings(Map & map, YAML::Node yaml);
	void loadEntities(Map & map, YAML::Node yaml);
	Entity * createEntity(Map & map, YAML::Node yaml);
};

#endif  // MAP_LOADER_H
