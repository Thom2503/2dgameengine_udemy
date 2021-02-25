#include <iostream>
#include "./Constants.h"
#include "./Game.h"
int main(int argc, char *args[])
{
    //game object points to game.h
    Game game;

    //parameters are constants in constants.h
    game.Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    //crude game loop
    while(game.IsRunning())
    {
      game.ProcessInput();
      game.Update();
      game.Render();
    }

    game.Destroy();

    return 0;
}
