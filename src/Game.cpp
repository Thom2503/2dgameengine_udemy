#include <iostream>
#include "./Constants.h"
#include "./Game.h"
#include "../lib/glm/glm.hpp"

EntityManager manager;
SDL_Renderer* Game::renderer;

Game::Game()
{
  this->isRunning = false;
}

Game::~Game()
{

}

bool Game::IsRunning() const
{
  return this->isRunning;
}

// float projectilePosX = 0.0f;
// float projectilePosY = 0.0f;
// float projectileVelX = 20.0f;
// float projectileVelY = 30.0f;
// glm::vec2 projectilePos = glm::vec2(0.0f, 0.0f);
// glm::vec2 projectileVel = glm::vec2(20.0f, 30.0f);

void Game::Initialize(int width, int height)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    std::cerr << "Error Initializing SDL" << std::endl;
    return;
  }

  //creates a window
  window = SDL_CreateWindow(
    "Window test",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    width,
    height,
    0
  );

  if (!window)
  {
    std::cerr << "Error creating a SDL window" << std::endl;
    return;
  }

  //create a renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  //is the renderer okay? otherwise return an error.
  if (!renderer)
  {
    std::cerr << "Error creating a SDL renderer" << std::endl;
    return;
  }

  isRunning = true;
}

void Game::ProcessInput()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type)
  {
    case SDL_QUIT:
    {
      isRunning = false;
      break;
    }
    case SDL_KEYDOWN:
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
      {
        isRunning = false;
      }
    }
    default:
    {
      break;
    }
  }
}

void Game::Update()
{
  //was a while loop but that maxed out the cpu core and thats not good :)
  // Waste some time / sleep until we reach the target frame time in milliseconds
  int timeToWait = FRAME_TARGET_TIME - (SDL_GetTicks() - ticksLastFrame);

  // Only sleep if we are too fast
  if (timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
  {
    SDL_Delay(timeToWait);
  }

  //delta time is the difference in ticks from last frame converted to seconds
  float deltatime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

  //clamp delta time to a maximum value
  deltatime = (deltatime > 0.05) ? 0.05f : deltatime;

  //sets the new ticks for the current fram to be used in the next pass
  ticksLastFrame = SDL_GetTicks();

  //TODO:
  //here we call the manager.update to update our entities

  // projectilePosX += projectileVelX * deltatime;
  // projectilePosY += projectileVelY * deltatime;
  //use deltatime to update the game objects
  //projectilePos = glm::vec2(projectilePos.x + projectileVel.x * deltatime, projectilePos.y + projectileVel.y * deltatime);
}

void Game::Render()
{
  SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
  SDL_RenderClear(renderer);

  //TODO:
  //here we call the manager to render our entities

  SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
