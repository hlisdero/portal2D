#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/map.h"
#include "server/entities/player.h"
#include "server/entities/utils/body_factory.h"
#include "server/physics/contact_listener.h"

/*
	y
	^
	|
	|
	*------ > x
*/

#define PORTAL_REACH 30.0f

class World {
public:
	explicit World(Map & map);

    void createPlayer(PlayerEntity * player);
    void createPortal(PlayerEntity & player, b2Vec2 & direction, PortalColor color);

    void updatePhysics();

	const std::vector<Entity*> getDynamicEntities() const;

	int getPlayersCount();
	
private:
	b2World world;
	BodyFactory bodyFactory;
	Map & map;

	std::vector<PlayerEntity*> players;

	ContactListener contactListener;
};

#endif  // WORLD_H
