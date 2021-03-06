//Here comes the code for the transform component like in Unity for example
#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "../src/EntityManager.h"
#include "../../lib/glm/glm.hpp"
#include <SDL2/SDL.h>
#include "../src/Game.h"

class TransformComponent: public Component
{
public:
  glm::vec2 position;
  glm::vec2 velocity;
  int width;
  int height;
  int scale;

  TransformComponent(int posX, int posY, int velX, int velY, int w, int h, int s)
  {
    position = glm::vec2(posX, posY);
    velocity = glm::vec2(velX, velY);
    width = w;
    height = h;
    scale = s;
  }

  void Initialize() override
  {

  }

  void Update(float deltatime) override
  {
    position.x += velocity.x * deltatime;
    position.y += velocity.y * deltatime;
  }

  void Render() override
  {
    SDL_Rect transformRectangle = {
      (int) position.x,
      (int) position.y,
      width,
      height
    };

    SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(Game::renderer, &transformRectangle);
  }
};


#endif
