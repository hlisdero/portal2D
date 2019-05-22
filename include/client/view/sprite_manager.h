#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <vector>
#include "client/view/sprite.h"
#include "client/view/color.h"
#include "client/view/texture_creator.h"
#include "common/entities/entity.h"

class SpriteManager {
public:
    SpriteManager(const TextureCreator& textureCreator);

    Sprite& getSprite(EntityType type) const;

    ~SpriteManager();

private:
    std::vector<Sprite*> sprites;
};

#endif  // SPRITE_MANAGER_H
