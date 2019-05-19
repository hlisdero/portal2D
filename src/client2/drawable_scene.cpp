#include "client2/drawable_scene.h"

DrawableScene::DrawableScene(int pixelWidth, int pixelHeight, 
	int meterWidth, int meterHeight) : Scene(), 
	width(pixelWidth), height(pixelHeight),
	scaleFactorX(pixelWidth/meterWidth), scaleFactorY(pixelHeight/meterHeight) {}

void DrawableScene::setEntities(const std::vector<MEntity> staticEntities, const std::vector<MEntity> dynamicEntities) {
	this->staticEntities = transformToPEntities(staticEntities);
	this->dynamicEntities = transformToPEntities(dynamicEntities); 
}

void DrawableScene::setDynamicEntities(const std::vector<MEntity> dynamicEntities) {
	this->dynamicEntities = transformToPEntities(dynamicEntities); 
}

PEntity DrawableScene::transfromToPEntity(const MEntity mEntity) {
	int pixelX = mEntity.getX() * this->scaleFactorX;
	int pixelY = mEntity.getY() * this->scaleFactorY;
	return PEntity(mEntity.getType(), pixelX, pixelY);
}

std::vector<PEntity> DrawableScene::transformToPEntities(const std::vector<MEntity> & mEntities) {
	std::vector<PEntity> pEntities;

	for(uint i = 0; i < mEntities.size(); i++) {
		pEntities.push_back(this->transfromToPEntity(mEntities[i]));
	}

	return pEntities;
}