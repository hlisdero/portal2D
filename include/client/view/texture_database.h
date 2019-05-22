#ifndef TEXTURE_DATABASE_H
#define TEXTURE_DATABASE_H

#include "client/view/sprite.h"
#include "client/view/color.h"
#include "client/view/texture_creator.h"
#include "common/entities/entity.h"

class SpriteDatabase {
public:
    SpriteDatabase(const TextureCreator & textureCreator);

    Sprite & getSprite(EntityType type);
private:
    Sprite * sprites[25];
};

#endif  // TEXTURE_DATABASE_H
