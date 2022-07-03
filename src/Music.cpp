#include "Music.hpp"

Music::Music()
{
    music = nullptr;
}

Music::Music(string file)
{
    Open(file);
}

void Music::Play(int times)
{
    if (music != nullptr)
    {
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop)
{
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file)
{
    music = Mix_LoadMUS(file.c_str());

    if (Mix_LoadMUS(file.c_str()) == nullptr)
    {
        printf("Could not load music: %s\n", SDL_GetError());
    }
}

bool Music::IsOpen()
{
    if (music == nullptr)
    {
        return false;
    }
    return true;
}

Music::~Music()
{
    Stop(0);
    Mix_FreeMusic(music);
}
