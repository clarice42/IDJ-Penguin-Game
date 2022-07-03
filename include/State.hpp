#ifndef STATE_HPP
#define STATE_HPP
#endif

#include "Sprite.hpp"
#include "Music.hpp"
#include <iostream>

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