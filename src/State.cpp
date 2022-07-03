#include "State.hpp"

State::State()
{
    quitRequested = false;
}

void State::LoadAssets()
{
    bg.Open("assets/ocean.jpg");
    music.Open("assets/stageState.ogg");
    music.Play();
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