#ifndef DRAWABLE_SCENE_H
#define DRAWABLE_SCENE_H

#include <vector>
#include "Box2D/Box2D.h"

#include "common/scene.h"
#include "common/entities/m_entity.h"

class DrawableScene : Scene {
public:
	DrawableScene();

	void setEntities(const std::vector<MEntity> staticEntities, const std::vector<MEntity> dynamicEntities);
	void setDynamicEntities(const std::vector<MEntity> dynamicEntities);
private:
	std::vector<MEntity> dynamicEntities;

};

#endif  // DRAWABLE_SCENE_H