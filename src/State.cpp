#include "State.hpp"

State::State()
{
    quitRequested = false;
    LoadAssets();
    music.Play();
}

void State::LoadAssets()
{
    bg.Open(BACKGROUND_PATH);
    music.Open(MUSIC_PATH);
}

void State::Update(float dt)
{
    if (SDL_QuitRequested())
    {
        quitRequested = true;
    }
}

void State::Render()
{
    bg.Render(0, 0);
}

bool State::QuitRequested()
{
    return quitRequested;
}