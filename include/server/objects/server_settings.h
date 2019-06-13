#ifndef SERVER_SETTINGS_H
#define SERVER_SETTINGS_H

#include <string>

#define LOOPS_PER_SECOND 60

class ServerSettings {
public:
	explicit ServerSettings(const char * filename);

	// server
	std::string PORT;
	
	// body factory
	float ENERGY_BALL_SPEED;
	float DYNAMIC_BODY_DENSITY;

	// contact_listener 
	double CONTACT_THRESHOLD;

	// world
	float TIME_STEP = 1.0f / LOOPS_PER_SECOND; // Not loaded from file
	int VELOCITY_ITERATIONS;
	int POSITION_ITERATIONS;

	float GRAVITY;

	float PORTAL_REACH;
	double PORTAL_SENSIBILITY;

	int ENERGY_EMITTER_INTERVAL;

	// player
	float PLAYER_SPEED;
	float PLAYER_AIR_SPEED;
	float PLAYER_JUMP_IMPULSE;
	float VERTICAL_VECTOR_LIMIT;
	float MAX_FALL_SPEED;
};

#endif