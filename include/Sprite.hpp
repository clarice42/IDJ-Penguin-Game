#ifndef SPRITE_HPP
#define SPRITE_HPP

#define INCLUDE_SDL_IMAGE
#include "SDL_include.hpp"
#include <iostream>

using namespace std;

class Sprite
{
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;

public:
    Sprite();
    Sprite(string);
    ~Sprite();
    void Open(string);
    void SetClip(int, int, int, int);
    void Render(int, int);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
};

#endif