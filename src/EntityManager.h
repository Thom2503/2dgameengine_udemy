#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "./Entity.h"
#include "./Components.h"
#include <vector>

class EntityManager
{
  private:
    std::vector<Entity*> entities;
  public:
    void Update(float deltatime);
    void Render();
    bool HasNoEntities();
    Entity& AddEntity(std::string entityName);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount();
}

#endif
