#ifndef GAME_HPP
#define GAME_HPP

#define INCLUDE_SDL
#include "SDL_include.hpp"
#include <SDL2/SDL.h>
#include "State.hpp"
#include <iostream>
#include <cstdlib>

#define GAME_TITLE "Clara Resende Maia - 180030931"
#define GAME_WIDTH 1024
#define GAME_HEIGHT 600

using namespace std;

class Game
{
private:
    Game(string, int, int);
    static Game *instance;
    SDL_Window *window;
    SDL_Renderer *renderer;
    State *state;
    int frameStart;
    float dt;
    void CalculateDeltaTime();

public:
    ~Game();
    void Run();
    SDL_Renderer *GetRenderer();
    State &GetState();
    static Game &GetInstance();
    float GetDeltaTime();
};

#endif