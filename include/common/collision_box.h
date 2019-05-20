#ifndef COLLISION_BOX_H
#define COLLISION_BOX_H

#include <Box2D/Box2D.h>

class CollisionBox {
public:
    explicit CollisionBox(b2Body *body);

    CollisionBox(const CollisionBox&) = delete;
    CollisionBox& operator=(const CollisionBox&) = delete;

    CollisionBox(CollisionBox&& other);
    CollisionBox& operator=(CollisionBox&& other);

    void setPosition(float32 x, float32 y);
    void setPosition(b2Vec2 position);
    b2Vec2 getPosition() const;
    float32 getAngle() const;

private:
    b2Body *body;
};

#endif  // COLLISION_BOX_H
