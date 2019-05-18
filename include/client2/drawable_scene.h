#ifndef DRAWABLE_SCENE_H
#define DRAWABLE_SCENE_H

#include <vector>
#include "Box2D/Box2D.h"

#include "common/scene.h"
#include "common/entity.h"

class DrawableScene : Scene {
public:
	DrawableScene();

	void setEntities(const std::vector<Entity> staticEntities, const std::vector<Entity> dynamicEntities);
	void setDynamicEntities(const std::vector<Entity> dynamicEntities);
private:
	std::vector<Entity> dynamicEntities;

};

#endif  // DRAWABLE_SCENE_H