#ifndef SERVER_SCENE_HPP
#define SERVER_SCENE_HPP

#include "Box2D/Box2D.h"

class ServerScene {
public:
	ServerScene();

    void create();

    void updatePhysics();

private:
	b2World world;

	void createGroundElements(b2Body * groundBody);
};

#endif  // SERVER_SCENE_HPP