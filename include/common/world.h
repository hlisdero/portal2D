#ifndef WORLD_H
#define WORLD_H

#include <Box2D/Box2D.h>
#include <vector>
#include "collision_box.h"

class World {
public:
    World(float32 width, float32 height);

    World(const World&) = delete;
    World& operator=(const World&) = delete;
    World(World&& other) = delete;
    World& operator=(World&& other) = delete;

    void update();

    CollisionBox& createCollisionBox(float32 width, float32 height);

private:
    float32 width;
    float32 height;
    b2World world;
    std::vector<CollisionBox> objects;

    void createBorders(float32 width, float32 height);
};

#endif  // WORLD_H
