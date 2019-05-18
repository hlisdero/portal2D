#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <map>
#include "Box2D/Box2D.h"

#include "common/entity.h"

class Scene {
public:
	Scene();

    void addPlayer();
    void updatePhysics();

private:
	b2World world;
	std::vector<Entity> staticEntities;
	std::map<int, Entity> dynamicEntities;

	void createStaticEntities(b2Body * groundBody);
	void createStaticEntity(b2Body * groundBody, Entity entity);
	void createDynamicEntities();
	void createDynamicEntity();
};

#endif  // SCENE_H