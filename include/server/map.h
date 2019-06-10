#ifndef MAP_H
#define MAP_H

#include "Box2D/Box2D.h"
#include "yaml-cpp/yaml.h"

#include <map>
#include <string>
#include <vector>

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

	EndZone & getEndZone();
	b2Vec2 & getSpawn();
	int getMinPlayers() const;

	~Map();

private:
	int minPlayers;
	b2Vec2 spawn;

	std::vector<Entity*> staticEntities;
	std::vector<Entity*> dynamicEntities;

	EndZone endZone;

	GameEventCreator& gameEventCreator;

	void loadSettings(YAML::Node yaml);
	void loadEntities(YAML::Node yaml);
	Entity * createEntity(YAML::Node yaml);

    EntityType getEntityType(std::string str);
};

#endif  // MAP_H
