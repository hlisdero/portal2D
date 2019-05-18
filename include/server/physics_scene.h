#ifndef PHYSICS_SCENE_H
#define PHYSICS_SCENE_H

#include "Box2D/Box2D.h"

#include "common/scene.h"
#include "common/entity.h"
#include "server/player_entity.h"

/*
	y
	^
	|
	|
	*------ > x
*/

class PhysicsScene : Scene {
public:
	PhysicsScene();

    void createPlayer(PlayerEntity & player);
    void updatePhysics();

	std::vector<Entity> getStaticEntities() const;
	std::vector<Entity> getDynamicEntities() const;
private:
	b2World world;
	std::vector<PlayerEntity*> players;

	void createStaticEntities(b2Body * groundBody);
	void createStaticEntity(b2Body * groundBody, const Entity entity);
	void createDynamicEntities();
	void createDynamicEntity(Entity entity);
};

#endif  // PHYSICS_SCENE_H