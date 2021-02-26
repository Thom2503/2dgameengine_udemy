#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
  public:
    Entity* owner;
    virtual ~Component() ()
    virtual void Initialize() ()
    virtual void Update(float deltatime) ()
    virtual void Render() ()
};

#endif
