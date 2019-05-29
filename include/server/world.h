#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/player.h"
#include "server/entities/body_factory.h"
#include "server/contact_listener.h"
#include "server/map.h"

/*
	y
	^
	|
	|
	*------ > x
*/

class World {
public:
	explicit World(Map & map);

    void createPlayer(PlayerEntity * player);

    void updatePhysics();

	const std::vector<Entity*> getDynamicEntities() const;
private:
	b2World world;
	BodyFactory bodyFactory;
	Map & map;

	std::vector<PlayerEntity*> players;

	ContactListener contactListener;
};

#endif  // WORLD_H
