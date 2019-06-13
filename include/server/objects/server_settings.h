#ifndef SERVER_SETTINGS_H
#define SERVER_SETTINGS_H

#include <string>

#define LOOPS_PER_SECOND 60

class ServerSettings {
public:
	explicit ServerSettings(const char * filename);

	// server
	std::string PORT = "8080";
	
	// body factory
	float ENERGY_BALL_SPEED = 2.0f;
	float DYNAMIC_BODY_DENSITY = 1.0f;

	// contact_listener 
	double CONTACT_THRESHOLD = 0.01;

	// world
	float TIME_STEP = 1.0f / LOOPS_PER_SECOND; // Not loaded from file
	int VELOCITY_ITERATIONS = 6;
	int POSITION_ITERATIONS = 2;

	float GRAVITY = -10.0f;

	float PORTAL_REACH = 30.0f;
	double PORTAL_SENSIBILITY = 0.8; 

	int ENERGY_EMITTER_INTERVAL = 5;

	// player
	float PLAYER_SPEED = 5.0f;
	float PLAYER_AIR_SPEED;
	float PLAYER_JUMP_IMPULSE = 5.0f;
	float VERTICAL_VECTOR_LIMIT = 0.707;
};

#endif