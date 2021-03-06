#include "server/entities/player.h"

#include "server/entities/rock.h"
#include "server/physics/grab_rock_callback.h"

#include "server/objects/server_settings.h"
extern ServerSettings SETTINGS;

PlayerEntity::PlayerEntity(b2Vec2 position, GameEventCreator& gameEventCreator) :
	TeleportableEntity(TYPE_PLAYER, position.x, position.y, 0, gameEventCreator) {
	for(int i = 0; i < PORTALS_NB; i++) {
		portals[i] = nullptr;
	}

	grabRockShape.m_radius = SETTINGS.GRAB_REACH;
}

PlayerEntity::~PlayerEntity() {
	for(int i = 0; i < PORTALS_NB; i++) {
		if(portals[i] != nullptr) {
			delete portals[i];
		}
	}

	if(carriedRock != nullptr) {
		carriedRock->release(NONE);
	}
}

PortalEntity * PlayerEntity::getPortal(PortalColor color) {
	return portals[color];
}

void PlayerEntity::setPortal(PortalColor color, PortalEntity * portal) {
	PortalEntity * twin = portals[(color+1)%PORTALS_NB];
	if(twin != nullptr) {
		twin->setTwin(portal);
		portal->setTwin(twin);
	}
	portals[color] = portal;
}

void PlayerEntity::resetPortals(b2World & world, EventCreator & eventCreator) {
	for(int i = 0; i < PORTALS_NB; i++) {
		if(portals[i] != nullptr) {
			eventCreator.addEntityDestruction(portals[i]);
			world.DestroyBody(portals[i]->getBody());
			delete portals[i];

			portals[i] = nullptr;
		}
	}
}

void PlayerEntity::handleFloorContact(b2Contact * contact, bool newContact) {
	if(newContact) {
		b2WorldManifold worldManifold;
		contact->GetWorldManifold(&worldManifold);

		if(abs(worldManifold.normal.y) > SETTINGS.VERTICAL_VECTOR_LIMIT) {
			floorsContacts.insert(contact);
			inTheAir = false;
		}
	} else {
		floorsContacts.erase(contact);
		inTheAir = (floorsContacts.size() == 0);
	}
}

void PlayerEntity::handleContactWith(Entity * other, b2Contact * contact, bool inContact) {
	// If other is not a sensor
	if(other->getType() != TYPE_ENERGY_BAR &&
		other->getType() != TYPE_END_BARRIER &&
		other->getType() != TYPE_ENERGY_BALL) {
		handleFloorContact(contact, inContact);
	}

	TeleportableEntity::handleContactWith(other, contact, inContact);

	switch(other->getType()) {
		case TYPE_END_BARRIER:
			gameEventCreator.addPortalsReset(this);
			/* fall through */
		case TYPE_ENERGY_BAR:
			if(carriedRock != nullptr) {
				carriedRock->release(NONE);
				carriedRock->respawn();
				carriedRock = nullptr;
			}
			break;
		case TYPE_ENERGY_BALL:
		case TYPE_ACID:
			gameEventCreator.addKillPlayer(this);
			destroy();
			break;
		default:
			break;
	}
}

void PlayerEntity::grabReleaseRock(b2World & b2world) {
	if(carriedRock != nullptr) {
		carriedRock->release(lastDirection);
		carriedRock = nullptr;
	} else {
		RockEntity* rock = getRock(b2world);

		if(rock != nullptr && rock->getHolder() == nullptr) {
			carriedRock = rock;
			rock->grab(this);
		}
	}
}

void PlayerEntity::move(const MoveDirection& direction, bool pressed) {
	if (pressed) {
		switch(direction) {
			// If on the floor, jump
			case UP:
				if(!inTheAir) {
					b2Vec2 velocity = getBody()->GetLinearVelocity();

					velocity.x = std::min(velocity.x, SETTINGS.PLAYER_AIR_SPEED);
					velocity.x = std::max(velocity.x, -1 * SETTINGS.PLAYER_AIR_SPEED);

					velocity.y = SETTINGS.PLAYER_JUMP_IMPULSE;
					getBody()->SetLinearVelocity(velocity);
					inTheAir = true;
				}
				break;
			case LEFT:
			case RIGHT:
				moveDirection = direction;
				lastDirection = direction;
				break;
			default:
				break;
		}
	} else if(moveDirection == direction) {
		moveDirection = NONE;
	}
}

void PlayerEntity::applyImpulseToCenter(const float vx, const float vy) {
	b2Vec2 vector(vx, vy);
	vector *= getBody()->GetMass();

	getBody()->ApplyLinearImpulse(vector, getBody()->GetWorldCenter(), true);
}

void PlayerEntity::applyMovement() {
	b2Vec2 velocity = getBody()->GetLinearVelocity();
	if(velocity.y < SETTINGS.MAX_FALL_SPEED) {
		velocity.y = SETTINGS.MAX_FALL_SPEED;
		getBody()->SetLinearVelocity(velocity);
	}

	float speed = SETTINGS.PLAYER_SPEED;

	if(inTheAir || isGoingThroughPortal()) {
		if(moveDirection == NONE) {
			return;
		}

		speed = SETTINGS.PLAYER_AIR_SPEED;
	}

	float targetVelocity;
	switch(moveDirection) {
		case RIGHT:
			targetVelocity = speed;
			break;
		case LEFT:
			targetVelocity = -1 * speed;
			break;
		default:
			targetVelocity = 0.0f;
			break;
	}

	float velocityX = (targetVelocity - velocity.x);
	applyImpulseToCenter(velocityX, 0.0f);
}

RockEntity * PlayerEntity::getRock(b2World & world) {
	b2AABB aabb;
	grabRockShape.ComputeAABB(&aabb, getBody()->GetTransform(), 0);

	GrabRockCallback callback(getBody()->GetPosition());
	world.QueryAABB(&callback, aabb);

	return callback.rock;
}