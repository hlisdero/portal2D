#include "server/objects/server_settings.h"

#include "yaml-cpp/yaml.h"

ServerSettings::ServerSettings(const char * filename) {
	YAML::Node yaml = YAML::LoadFile(filename);

	// server
	PORT = yaml["port"].as<std::string>();
	
	// body_factory
	ENERGY_BALL_SPEED = yaml["energy_ball_speed"].as<float>();
	DYNAMIC_BODY_DENSITY = yaml["dynamic_body_density"].as<float>();

	// contact_listener 
	CONTACT_THRESHOLD = yaml["contact_threshold"].as<double>();

	// world
	VELOCITY_ITERATIONS = yaml["velocity_iterations"].as<int>();
	POSITION_ITERATIONS = yaml["position_iterations"].as<int>();

	GRAVITY = yaml["gravity"].as<float>();

	PORTAL_REACH = yaml["portal_reach"].as<float>();
	PORTAL_SENSIBILITY = yaml["portal_sensibility"].as<double>();

	ENERGY_EMITTER_INTERVAL = yaml["energy_emitter_fire_interval"].as<int>();

	// player
	PLAYER_SPEED = yaml["player_speed"].as<float>();
	PLAYER_JUMP_IMPULSE = yaml["player_jump_impulse"].as<float>();
	VERTICAL_VECTOR_LIMIT = yaml["vertical_vector_limit"].as<float>();
}

ServerSettings SETTINGS("../data/server_settings.yaml");