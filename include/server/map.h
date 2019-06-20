#ifndef MAP_H
#define MAP_H

#include "Box2D/Box2D.h"
#include "yaml-cpp/yaml.h"

#include <map>
#include <string>
#include <vector>

#include "common/objects/size.h"
#include "server/entities/entity.h"
#include "server/entities/gate.h"
#include "server/entities/energy_emitter.h"
#include "server/entities/energy_receiver.h"
#include "server/entities/button.h"
#include "server/entities/rock.h"
#include "server/entities/end_barrier.h"
#include "server/physics/end_zone.h"
#include "server/entities/utils/gate_logica.h"
#include "server/events/game_event_creator.h"

class Map {
public:
	Map(const std::string& map_name, GameEventCreator & gameEventCreator);

	const std::vector<Entity*> & getStaticEntities() const;
	const std::vector<Entity*> & getDynamicEntities() const;

	b2Vec2 & getSpawn();
	size_t getMinPlayers() const;

	const Size & getSize() const;

	~Map();

private:
	size_t minPlayers;
	b2Vec2 spawn;

	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	EndZone endZone;

	float minX = -1;
	float minY;
	float maxX;
	float maxY;

	Size size = {0,0};

	GameEventCreator& gameEventCreator;

	void loadSettings(const YAML::Node & yaml);
	void loadEntities(const YAML::Node & yaml);
	Entity * createEntity(const YAML::Node & yaml);

    EntityType getEntityType(std::string str);
    void initMapDimensions(float x, float y);
    void updateMapDimensions(float x, float y);
};

#endif  // MAP_H
