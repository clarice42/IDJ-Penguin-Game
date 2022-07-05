#ifndef SPRITE_HPP
#define SPRITE_HPP

#define INCLUDE_SDL_IMAGE
#include "SDL_include.hpp"
#include "Component.hpp"
#include <iostream>

using namespace std;

class Sprite : public Component
{
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite(GameObject&);
    Sprite(string, GameObject&);
    ~Sprite();
    void Open(string);
    void SetClip(int, int, int, int);
    void Render();
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update(float);
    bool Is(string);
};

#endif