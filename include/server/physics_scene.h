#ifndef PHYSICS_SCENE_H
#define PHYSICS_SCENE_H

#include <vector>

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"
#include "server/entities/player.h"
#include "server/entities/entity_factory.h"
#include "server/contact_listener.h"

/*
	y
	^
	|
	|
	*------ > x
*/

class PhysicsScene {
public:
	PhysicsScene();

    void createPlayer(PlayerEntity * player);
    void updatePhysics();

	std::vector<Entity> getStaticEntities() const;
	std::vector<Entity> getDynamicEntities() const;
private:
	b2World world;
	EntityFactory entityFactory;

	std::vector<Entity*> staticEntities;
	std::vector<PlayerEntity*> players;

	ContactListener contactListener;

	void createStaticEntities(b2Body * groundBody);
	void createStaticEntity(b2Body * groundBody, const Entity & entity);
	void createDynamicEntities();
	void createDynamicEntity(Entity & entity);
};

#endif  // PHYSICS_SCENE_H
