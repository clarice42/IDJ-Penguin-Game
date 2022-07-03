#ifndef STATE_HPP
#define STATE_HPP

#include "Sprite.hpp"
#include "Music.hpp"
#include <iostream>

#define BACKGROUND_PATH "assets/ocean.jpg"
#define MUSIC_PATH "assets/stageState.ogg"

using namespace std;

class State
{
private:
    Sprite bg;
    Music music;
    bool quitRequested;

public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float);
    void Render();
};

#endif