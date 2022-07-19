#include "Music.hpp"
#include "Resources.hpp"

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
    music = Resources::GetMusic(file);
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
}
