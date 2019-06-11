#include "server/physics/portal_aabb_callback.h"

#include "server/entities/player.h"

PortalAABBCallback::PortalAABBCallback(b2Vec2 edgeA, b2Vec2 edgeB) :
	edgeA(std::move(edgeA)), edgeB(std::move(edgeB)) {}

bool PortalAABBCallback::ReportFixture(b2Fixture* fixture) {
	Entity* entity = static_cast<Entity*>(
			fixture->GetBody()->GetUserData());

	if(entity->getType() == TYPE_PORTAL) {
		return true;
	}

	if(fixture->TestPoint(edgeA)) {
		edgeAInTheAir = false;
		isValid = isPointOk(entity);
	}

	if(isValid && fixture->TestPoint(edgeB)) {
		edgeBInTheAir = false;
		isValid = isPointOk(entity);
	}

	return isValid;
}

bool PortalAABBCallback::isPointOk(Entity* entity) {
	return entity->getType() == TYPE_METAL_BLOCK ||
			entity->getType() == TYPE_METAL_DIAG_BLOCK;
}

bool PortalAABBCallback::isOk() {
	return isValid && !edgeAInTheAir && !edgeBInTheAir;
}