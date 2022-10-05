#include "Game.hpp"
#include "Resources.hpp"
#include "Camera.hpp"

Sprite::Sprite(GameObject &associated) : Component(associated)
{
    texture = nullptr;
    associated.box.w = width;
    associated.box.h = height;
    scale.x = 1;
    scale.y = 1;
    frameCount = 1;
    frameTime = 1;
    currentFrame = 0;
    timeElapsed = 0;
}

Sprite::Sprite(string file, int recFrameCount, float recFrameTime, GameObject &associated) : Component(associated)
{
    frameCount = recFrameCount;
    frameTime = recFrameTime;
    currentFrame = 0;
    timeElapsed = 0;
    texture = nullptr;
    scale.x = 1;
    scale.y = 1;
    Open(file);
}

Sprite::~Sprite() {}

void Sprite::Open(string file)
{
    texture = Resources::GetImage(file.c_str());

    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) == -1)
    {
        printf("Invalid texture: %s\n", SDL_GetError());
    }

    SetClip(0, 0, width/frameCount, height);
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
    SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, associated.angleDeg, nullptr, SDL_FLIP_NONE);
}

void Sprite::Render()
{
    Render(associated.box.x - Camera::pos.x, associated.box.y - Camera::pos.y);
}

int Sprite::GetWidth()
{
    return (width * scale.x) / frameCount;
}

int Sprite::GetHeight()
{
    return height * scale.y;
}

bool Sprite::IsOpen()
{
    if (texture != nullptr)
    {
        return true;
    }
    return false;
}

void Sprite::Update(float dt)
{
    timeElapsed += dt;

    if (timeElapsed > frameTime)
    {
        currentFrame++;

        if (currentFrame >= frameCount)
        {
            currentFrame = 0;
        }

        int frameWidth = width / frameCount;
        int currentFramePosition = frameWidth * currentFrame;
        SetClip(currentFramePosition, 0, frameWidth, height);
        timeElapsed = 0;
    }
}

bool Sprite::Is(string type)
{
    if (type == "Sprite")
    {
        return true;
    }

    return false;
}

void Sprite::SetScale(float scaleX, float scaleY)
{
    if (!scaleX || !scaleY)
    {
        scale.x = 1;
        scale.y = 1;
    }

    scale.x = scaleX;
    scale.y = scaleY;
}

Vec2 Sprite::GetScale()
{
    return scale;
}

void Sprite::SetFrame(int frame)
{
    currentFrame = frame;

    int frameWidth = width / frameCount;
    int currentFramePosition = frameWidth * currentFrame;
    SetClip(currentFramePosition, 0, frameWidth, height);
}

void Sprite::SetFrameCount(int recFrameCount)
{
    frameCount = recFrameCount;

    associated.box.w = width / frameCount;
    associated.box.h = height;
    scale.x = 1;
    scale.y = 1;

    currentFrame = 0;
}

void Sprite::SetFrameTime(float recFrameTime)
{
    frameTime = recFrameTime;
}