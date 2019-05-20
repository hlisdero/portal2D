#ifndef PHYSICS_SCENE_H
#define PHYSICS_SCENE_H

#include "Box2D/Box2D.h"

#include "common/scene.h"
#include "common/entities/m_entity.h"
#include "server/player_entity.h"
#include "server/contact_listener.h"

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

	std::vector<MEntity> getStaticEntities() const;
	std::vector<MEntity> getDynamicEntities() const;
private:
	b2World world;
	
	std::vector<MEntity> staticEntities;
	std::vector<PlayerEntity*> players;

	ContactListener contactListener;

	void createStaticEntities(b2Body * groundBody);
	void createStaticEntity(b2Body * groundBody, const MEntity entity);
	void createDynamicEntities();
	void createDynamicEntity(MEntity entity);
};

#endif  // PHYSICS_SCENE_H