#include "client2/drawable_scene.h"

DrawableScene::DrawableScene(int pixelWidth, int pixelHeight, 
	int meterWidth, int meterHeight) : Scene(), 
	screen(pixelWidth, pixelHeight),
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
	int pixelY = this->height - mEntity.getY() * this->scaleFactorY;
	// TODO use something to load all the texture before
	return PEntity(mEntity.getType(), pixelX, pixelY, this->screen.getTextureCreator());
}

void DrawableScene::poolEvent() {
	this->eventHandler.poll();
}

bool DrawableScene::doQuit() {
	return this->eventHandler.doQuit();
}

void DrawableScene::render() {
	this->screen.setRenderDrawColor("white");
	this->screen.clear();

	for(uint i = 0; i < this->staticEntities.size(); i++) {
		this->screen.render(this->staticEntities[i]);
	}
	for(uint i = 0; i < this->dynamicEntities.size(); i++) {
		this->screen.render(this->dynamicEntities[i]);
	}
}

void DrawableScene::updateScreen() {	
	this->screen.update();
}

std::vector<PEntity> DrawableScene::transformToPEntities(const std::vector<MEntity> & mEntities) {
	std::vector<PEntity> pEntities;

	for(uint i = 0; i < mEntities.size(); i++) {
		pEntities.push_back(this->transfromToPEntity(mEntities[i]));
	}

	return pEntities;
}