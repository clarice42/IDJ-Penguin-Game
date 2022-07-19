#ifndef STATE_HPP
#define STATE_HPP

#define INCLUDE_SDL
#include "SDL_include.hpp"
#include <SDL2/SDL.h>
#include "Sprite.hpp"
#include "Music.hpp"
#include "Face.hpp"
#include "Vec2.hpp"
#include <iostream>
#include <vector>
#include <memory>

#define BACKGROUND_PATH "assets/ocean.jpg"
#define MUSIC_PATH "assets/stageState.ogg"
#define TILESET_PATH "assets/tileset.png"
#define TILEMAP_PATH "assets/tileMap.txt"
#define PENGUIN_FACE "assets/penguinface.png"
#define EXPLOSION_SOUND "assets/boom.wav"
#define PI 3.14159265359

using namespace std;

class State
{
private:
    Sprite *bg;
    Music music;
    bool quitRequested;
    void Input();
    void AddObject(int, int);
    vector<unique_ptr<GameObject>> objectArray;

public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float);
    void Render();
};

#endif