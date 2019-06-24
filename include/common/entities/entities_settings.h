#ifndef ENTITIES_SETTINGS_H
#define ENTITIES_SETTINGS_H

#include "common/entities/entities_types.h"

enum EntitySetting {
    X_OFFSET = 0,
    Y_OFFSET = 1,
    HALF_WIDTH = 2,
    HALF_HEIGHT = 3,
};

const float entitiesSettings[ENTITY_TYPES_LENGTH][4] = {
	// {x_offset, y_offset, half-width, half-height}

	{0.0f, 0.0f, 0.5f, 0.5f},      // TYPE_STONE_BLOCK
	{0.0f, 0.0f, 0.5f, 0.5f},      // TYPE_METAL_BLOCK
	{0.0f, 0.0f, 0.5f, 0.5f},      // TYPE_METAL_DIAG_BLOCK
	{0.0f, -0.40f, 0.5f, 0.15f},    // TYPE_ACID
	{0.0f, -0.5f, 0.5f, 1.0f},      // TYPE_GATE
	{0.0f, 0.0f, 0.05f, 0.5f},     // TYPE_ENERGY_BAR
	{0.0f, 0.0f, 0.5f, 0.5f},      // TYPE_ENERGY_EMITTER
	{0.0f, 0.0f, 0.5f, 0.5f},      // TYPE_ENERGY_RECEIVER
	{0.0f, -0.4f, 0.5f, 0.10f},  // TYPE_BUTTON
	{0.0f, 0.0f, 0.05f, 0.5f},    // TYPE_PORTAL
	{0.0f, 0.0f, 0.05f, 0.5f},     // TYPE_END_BARRIER
	{-0.4f, 0.0f, 0.30f, 0.30f},    // TYPE_PIN_TOOL
	{0.0f, 0.0f, 0.20f, 0.20f},    // TYPE_ROCK
	{0.0f, 0.0f, 0.2f, 0.40f},     // TYPE_PLAYER
	{0.0f, 0.0f, 0.30f, 0.30f},    // TYPE_ENERGY_BALL
};

#define BUTTON_TOP_SIZE_PERCENTAGE 0.5

#endif