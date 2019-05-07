#ifndef TALLER_TEST_H
#define TALLER_TEST_H

class TallerTest : public Test
{
private:
	b2Body* playerBody;
public:

	TallerTest()
	{
		// m_world: World object, created by the test

		// scope ground
		{
			b2BodyDef groundBodyDef;
			b2Body* groundBody = m_world->CreateBody(&groundBodyDef);

			// Define the ground box shape.
			b2PolygonShape jumpBox;

			b2Vec2 jumpBoxPosition(0.0f, 10.0f);
			// The extents are the half-widths of the box.
			jumpBox.SetAsBox(10.0f, 0.5f, jumpBoxPosition, 0.0f);

			// Add the ground fixture to the ground body.
			groundBody->CreateFixture(&jumpBox, 0.0f);


			// b2EdgeShape floor;
			// b2Vec2 floorStart(-30.0f, 0.0f);
			// b2Vec2 floorEnd(30.0f, 0.0f);
			// floor.Set(floorStart, floorEnd);
			// groundBody->CreateFixture(&floor, 0.0f);

			b2ChainShape underFloor;

			b2Vec2 vs[4];
			vs[0].Set(-50.0f, 50.0f);
			vs[1].Set(-30.0f, -20.0f);
			vs[2].Set(30.0f, -20.0f);
			vs[3].Set(50.0f, 50.0f);
			underFloor.CreateChain(vs, 4);

			b2FixtureDef fixDef;
			fixDef.restitution = 0.9;
			fixDef.shape = &underFloor;
			// Add the ground fixture to the ground body.
			groundBody->CreateFixture(&fixDef);
		}

		// Player
		{
			b2BodyDef playerBodyDef;
			playerBodyDef.position.Set(0.0f, 30.0f);
			playerBodyDef.type = b2_dynamicBody;
			this->playerBody = m_world->CreateBody(&playerBodyDef);

			b2PolygonShape body;
			body.SetAsBox(0.25f, 0.5f, b2Vec2(0.0f, 0.3f), 0.0f);

			b2CircleShape head;
			head.m_p.Set(0.0f, 1.0f);
			head.m_radius = 0.2f;

			b2PolygonShape leg1;
			leg1.SetAsBox(0.125f, 0.5f, b2Vec2(-0.250,-0.6f), -0.10f * b2_pi);
			b2PolygonShape leg2;
			leg2.SetAsBox(0.125f, 0.5f, b2Vec2(0.250,-0.6f), 0.10f * b2_pi);

			b2PolygonShape arm1;
			arm1.SetAsBox(0.125f, 0.4f, b2Vec2(-0.550,0.6f), -0.60f * b2_pi);

			b2PolygonShape arm2;
			arm2.SetAsBox(0.125f, 0.4f, b2Vec2(0.550,0.6f), 0.60f * b2_pi);

			this->playerBody->CreateFixture(&body, 1.0f);
			this->playerBody->CreateFixture(&head, 1.0f);
			this->playerBody->CreateFixture(&leg1, 1.0f);
			this->playerBody->CreateFixture(&leg2, 1.0f);
			this->playerBody->CreateFixture(&arm1, 1.0f);
			this->playerBody->CreateFixture(&arm2, 1.0f);
		}

		// {
		// 	b2BodyDef playerBodyDef;
		// 	playerBodyDef.position.Set(0.0f, 30.0f);
		// 	playerBodyDef.type = b2_dynamicBody;
		// 	this->playerBody = m_world->CreateBody(&playerBodyDef);

		// 	b2PolygonShape body;
		// 	body.SetAsBox(0.5f, 1.0f);

		// 	this->playerBody->CreateFixture(&body, 1.0f);
		// }

		// Cube
		{
			b2BodyDef cubeDef;
			cubeDef.position.Set(-35.0f, 11.0f);
			cubeDef.type = b2_kinematicBody;
			b2Body* cubeBody = m_world->CreateBody(&cubeDef);

			cubeBody->SetLinearVelocity(b2Vec2(12.0f, 0.0f));

			b2PolygonShape body;
			body.SetAsBox(0.5f, 0.5f);

			cubeBody->CreateFixture(&body, 1.0f);
		}
	}

	void Keyboard(int key)
	{
		if(key == GLFW_KEY_Q) {
			b2Vec2 vector = this->playerBody->GetWorldVector(b2Vec2(0.0f, 15.0f));
			this->playerBody->ApplyLinearImpulseToCenter(vector, true);
		}
	}

	static Test* Create()
	{
		return new TallerTest;
	}
};

#endif
