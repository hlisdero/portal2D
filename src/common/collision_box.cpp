#include "collision_box.h"

CollisionBox::CollisionBox(b2Body *body) : body(body) {}

CollisionBox::CollisionBox(CollisionBox&& other) {
    body = other.body;
    other.body = nullptr;
}

CollisionBox& CollisionBox::operator=(CollisionBox&& other) {
    body = other.body;
    other.body = nullptr;
    return *this;
}

void CollisionBox::setPosition(float32 x, float32 y) {
    setPosition(b2Vec2(x, y));
}

void CollisionBox::setPosition(b2Vec2 position) {
    body->SetTransform(position, body->GetAngle());
}

b2Vec2 CollisionBox::getPosition() const {
    return body->GetPosition();
}

float32 CollisionBox::getAngle() const {
    return body->GetAngle();
}
