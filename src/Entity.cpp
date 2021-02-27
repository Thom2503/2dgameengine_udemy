#include "./Entity.h"


Entity::Entity(EntityManager& manager): manager(manager)
{
  this->isActive = true;
}

Entity::Entity(EntityManager& manager, std:string name): manager(manager), name(name)
{
  this->isActive = true;
}

void Entity::Update(float deltatime)
{
  for (auto& component: components)
  {
    component->Update(deltatime);
  }
}

void Entity::Render()
{
  for (auto& component: components)
  {
    component->Render();
  }
}

void Destroy()
{
  this->isActive = false;
}

bool Entity::IsActive() const
{
  return this->isActive;
}