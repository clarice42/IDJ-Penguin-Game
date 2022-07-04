#include "Game.hpp"

Sprite::Sprite(GameObject &associated) : Component(associated)
{
    texture = nullptr;
}

Sprite::Sprite(string file, GameObject &associated) : Component(associated)
{
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::Open(string file)
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
    }

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

    if (texture == nullptr)
    {
        printf("Could not create a texture: %s\n", SDL_GetError());
    }

    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) == -1)
    {
        printf("Invalid texture: %s\n", SDL_GetError());
    }

    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y)
{
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth()
{
    return width;
}

int Sprite::GetHeight()
{
    return height;
}

bool Sprite::IsOpen()
{
    if (texture != nullptr)
    {
        return true;
    }
    return false;
}

void Sprite::Update(float dt) {}

void Sprite::Render() {}

bool Sprite::Is(string type)
{
    if (type == "Sprite")
    {
        return true;
    }

    return false;
}