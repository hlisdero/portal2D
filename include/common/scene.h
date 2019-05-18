#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "common/entity.h"

class Scene {
public:
	Scene();

protected:
	std::vector<Entity> staticEntities;
};

#endif  // SCENE_H