#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include "Box2D/Box2D.h"

#include "server/entities/entity.h"

class ContactListener : public b2ContactListener {
private:
    virtual void BeginContact(b2Contact* contact) override;
    virtual void EndContact(b2Contact* contact) override;
    virtual void PreSolve(b2Contact * contact, const b2Manifold * oldManifold) override;

	void handlePreSolve(b2Fixture * fixtureA, b2Fixture * fixtureB, b2Contact * contact);

    void handleContact(b2Contact * contact, bool inContact);
    void broadcastContact(Entity * entityA, Entity * entityB, 
    	b2Contact * contact, bool inContact);
};

#endif

