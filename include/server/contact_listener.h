#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include "Box2D/Box2D.h"

#include "common/entities/entity.h"

class ContactListener : public b2ContactListener {
private:
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;
    void handleContact(b2Contact * contact, bool inContact);
    void broadcastContact(Entity * entityA, Entity * entityB, 
    	b2Contact * contact, bool inContact);
};

#endif
