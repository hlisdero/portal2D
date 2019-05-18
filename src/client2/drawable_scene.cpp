#include "client2/drawable_scene.h"

DrawableScene::DrawableScene() : Scene() {}

void DrawableScene::setEntities(const std::vector<Entity> staticEntities, const std::vector<Entity> dynamicEntities) {
	this->staticEntities = staticEntities;
	this->dynamicEntities = dynamicEntities; 
}

void DrawableScene::setDynamicEntities(const std::vector<Entity> dynamicEntities) {
	this->dynamicEntities = dynamicEntities; 
}