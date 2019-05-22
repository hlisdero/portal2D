#ifndef DRAWABLE_SCENE_H
#define DRAWABLE_SCENE_H

#include <vector>
#include "Box2D/Box2D.h"

#include "common/scene.h"
#include "server/entities/m_entity.h"
#include "client2/p_entity.h"
#include "client/view/screen.h"
#include "client/event/event_handler.h"
#include "client/event/keyboard_handler.h"
#include "client/view/texture_database.h"

class DrawableScene : Scene {
public:
	DrawableScene(int pixelWidth, int pixelHeight, 
		int meterWidth, int meterHeight);

	void addHandler(KeyboardHandler * handler);

	void setEntities(const std::vector<MEntity> staticEntities, const std::vector<MEntity> dynamicEntities);
	void setDynamicEntities(const std::vector<MEntity> dynamicEntities);

	bool doQuit();
	void render();
	void poolEvent();
	void updateScreen();
private:
	Screen screen;
	int width;
	int height;
	float scaleFactorX;
	float scaleFactorY;
	EventHandler eventHandler;
	SpriteDatabase spriteDatabase;

	std::vector<PEntity> staticEntities;
	std::vector<PEntity> dynamicEntities;

	std::vector<PEntity> transformToPEntities(const std::vector<MEntity> & mEntities);
	PEntity transfromToPEntity(const MEntity mEntity);
	Texture getTexture(EntityType type);

};

#endif  // DRAWABLE_SCENE_H