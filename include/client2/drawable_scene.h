#ifndef DRAWABLE_SCENE_H
#define DRAWABLE_SCENE_H

#include <vector>
#include "Box2D/Box2D.h"

#include "common/scene.h"
#include "common/entities/m_entity.h"
#include "common/entities/p_entity.h"

class DrawableScene : Scene {
public:
	DrawableScene(int pixelWidth, int pixelHeight, 
		int meterWidth, int meterHeight);

	void setEntities(const std::vector<MEntity> staticEntities, const std::vector<MEntity> dynamicEntities);
	void setDynamicEntities(const std::vector<MEntity> dynamicEntities);
private:
	int width;
	int height;
	float scaleFactorX;
	float scaleFactorY;

	std::vector<PEntity> staticEntities;
	std::vector<PEntity> dynamicEntities;

	std::vector<PEntity> transformToPEntities(const std::vector<MEntity> & mEntities);
	PEntity transfromToPEntity(const MEntity mEntity);

};

#endif  // DRAWABLE_SCENE_H