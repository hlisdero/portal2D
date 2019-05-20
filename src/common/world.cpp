#include "world.h"

World::World(float32 width, float32 height) :
    width(width), height(height), world(b2Vec2(0.0f, -10.0f)) {
    createBorders(width, height);
}

CollisionBox& World::createCollisionBox(float32 width, float32 height) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(this->width/2, this->height/2);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape boxShape;
    boxShape.SetAsBox(width, height);

    b2FixtureDef boxFixtureDef;
    boxFixtureDef.shape = &boxShape;
    boxFixtureDef.density = 1;
    body->CreateFixture(&boxFixtureDef);

    objects.emplace_back(body);
    return objects.back();
}

void World::update() {
    float32 timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

    world.Step(timeStep, velocityIterations, positionIterations);
}

void World::createBorders(float32 width, float32 height) {
    b2BodyDef borderBodyDef;
    borderBodyDef.position.Set(0, 0);
    borderBodyDef.type = b2_staticBody;
    b2Body* borderBody = world.CreateBody(&borderBodyDef);

    b2Vec2 vertices[4];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(width, 0.0f);
    vertices[2].Set(width, height);
    vertices[3].Set(0.0f, height);
    b2ChainShape chain;
    chain.CreateLoop(vertices, 4);
    borderBody->CreateFixture(&chain, 0.0f);
}
