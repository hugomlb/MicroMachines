#ifndef _MANEJADORDECONTACTOS_H_
#define _MANEJADORDECONTACTOS_H_

#include "3rd_party/Box2D-cmake/Box2D/Box2D/Box2D.h"

class ManejadorDeContactos: public b2ContactListener {
  public:
    ManejadorDeContactos();
    void BeginContact(b2Contact *contact);

    void EndContact(b2Contact *contact);

    ~ManejadorDeContactos();
};


#endif