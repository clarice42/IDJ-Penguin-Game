#include "Game.hpp"

Sprite::Sprite(GameObject &associated) : Component(associated)
{
    texture = nullptr;
    associated.box.w = width;
    associated.box.h = height;
}

Sprite::Sprite(string file, GameObject &associated) : Component(associated)
{
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(string file)
{
    texture = Resources::GetImage(file.c_str());

    if (texture == nullptr)
    {
        printf("Could not create a texture: %s\n");
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

void Sprite::Render(int x, int y) {
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

void Sprite::Render()
{
    Render(associated.box.x, associated.box.y);
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

bool Sprite::Is(string type)
{
    if (type == "Sprite")
    {
        return true;
    }

    return false;
}