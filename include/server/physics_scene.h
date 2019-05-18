#ifndef PHYSICS_SCENE_H
#define PHYSICS_SCENE_H

#include "Box2D/Box2D.h"

#include "common/scene.h"
#include "common/entity.h"

class PhysicsScene : Scene {
public:
	PhysicsScene();

    void addPlayer();
    void updatePhysics();

	std::vector<Entity> getStaticEntities();
	std::vector<Entity> getDynamicEntities();
private:
	b2World world;

	void createStaticEntities(b2Body * groundBody);
	void createStaticEntity(b2Body * groundBody, Entity entity);
	void createDynamicEntities();
	void createDynamicEntity(Entity entity);
};

#endif  // PHYSICS_SCENE_H