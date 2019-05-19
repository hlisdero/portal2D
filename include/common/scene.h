#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "common/entities/m_entity.h"

class Scene {
public:
	Scene();

protected:
	std::vector<MEntity> staticEntities;
};

#endif  // SCENE_H