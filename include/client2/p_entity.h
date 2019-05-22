#ifndef P_ENTITY_H
#define P_ENTITY_H

#include "common/entities/entity.h"
#include "client/view/sprite.h"
#include "client/view/texture_creator.h"

// PixelsEntity
class PEntity : public Entity<int> {
public:
	PEntity(EntityType type, int x, int y, const TextureCreator & textureCreator);

    Sprite & getSprite();
    // virtual int getWidth() const = 0;
	// virtual int getHeight() const = 0;
private:
	Sprite sprite;
};

#endif