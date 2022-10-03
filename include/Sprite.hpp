#ifndef SPRITE_HPP
#define SPRITE_HPP

#define INCLUDE_SDL_IMAGE
#include "SDL_include.hpp"
#include "Component.hpp"
#include "Vec2.hpp"
#include <iostream>

using namespace std;

class Sprite : public Component
{
private:
    SDL_Texture *texture;
    int width;
    int height;
    SDL_Rect clipRect;
    Vec2 scale;

public:
    Sprite(GameObject &);
    Sprite(string, GameObject &);
    ~Sprite();
    void Open(string);
    void SetClip(int, int, int, int);
    void Render();
    void Render(int, int);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update(float);
    bool Is(string);
    void Start(){};
    void SetScale(float, float);
    Vec2 GetScale();
};

#endif