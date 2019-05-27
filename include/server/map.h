#ifndef MAP_H
#define MAP_H

#include <vector>
#include "yaml-cpp/yaml.h"

#include "common/entities/entity.h"

class Map {
public:
	Map();

	// std::vector<Entity*> & getStaticEntities();

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> & getDynamicEntities() const;

	~Map();

private:
	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	void loadEntities(YAML::Node yaml);
	Entity * createEntity(YAML::Node yaml);
};

#endif  // MAP_H
