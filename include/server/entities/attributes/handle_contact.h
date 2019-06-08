#ifndef HANDLE_CONTACT_H
#define HANDLE_CONTACT_H

#include "Box2D/Box2D.h"
#include "server/entities/entity.h"

class HandleContact {
public:
    virtual void handleContactWith(Entity * other, b2Contact * contact, bool inContact) = 0;
};

#endif