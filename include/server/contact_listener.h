#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include "Box2D/Box2D.h"

class ContactListener : public b2ContactListener {
private: 
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};

#endif