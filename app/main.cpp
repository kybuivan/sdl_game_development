#include <Game.h>
const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[])
{
    Uint32 frameStart, frameTime;
    
    if(Game::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
    {
        DEBUG("Game Init");
    }
    else
    {
        return 1;
    }

    while(Game::Instance()->running())
    {
        frameStart = SDL_GetTicks();
        
        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();

        frameTime = SDL_GetTicks() - frameStart;
        if(frameTime< DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }
    Game::Instance()->clean();
    
    return 0;
}
