#ifndef GAME_HPP
#define GAME_HPP
#endif

#define INCLUDE_SDL
#include "SDL_include.hpp"
#include <SDL2/SDL.h>
#include "State.hpp"
#include <iostream>

using namespace std;

class Game
{
private:
    Game(string, int, int);
    static Game *instance;
    SDL_Window *window;
    SDL_Renderer *renderer;
    State *state;

public:
    ~Game();
    void Run();
    SDL_Renderer *GetRenderer();
    State &GetState();
    static Game &GetInstance();
};