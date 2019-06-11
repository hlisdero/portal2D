#include "server/physics/portal_aabb_callback.h"

#include "server/entities/player.h"

PortalAABBCallback::PortalAABBCallback(b2Vec2 edgeA, b2Vec2 edgeB, b2Vec2 & normal, Entity * centerEntity) :
	edgeA(std::move(edgeA)), edgeB(std::move(edgeB)), orientation(getPortalOrientation(normal)), centerEntity(centerEntity) {}

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
	if(entity->getType() != TYPE_METAL_BLOCK && 
		entity->getType() != TYPE_METAL_DIAG_BLOCK) {
		return false;
	}

	if(orientation == HORIZONTAL 
		&& entity->getY() == centerEntity->getY()) {
		return true;
	} else if (orientation == VERTICAL 
		&& entity->getX() == centerEntity->getX()) {
		return true;
	// Else if diagonal
	} else if(entity->getType() == TYPE_METAL_DIAG_BLOCK 
			&& entity->getRotationDeg() == centerEntity->getRotationDeg()) {
		return true;
	}

	return false;
}

PortalOrientation PortalAABBCallback::getPortalOrientation(b2Vec2 & normal) {
	if(normal.x == 0) {
		return HORIZONTAL;
	} else if(normal.y == 0) {
		return VERTICAL;
	} else {
		return DIAGONAL;
	}
}

bool PortalAABBCallback::isOk() {
	return isValid && !edgeAInTheAir && !edgeBInTheAir;
}