#include "Sound.hpp"
#include "Resources.hpp"

Sound::Sound(GameObject &associated) : Component(associated)
{
    chunk = nullptr;
}

Sound::Sound(GameObject &associated, string file) : Component(associated)
{
    Open(file);
}

void Sound::Play(int times)
{
    channel = Mix_PlayChannel(-1, chunk, times);
}

void Sound::Stop()
{
    if (chunk != nullptr)
    {
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(string file)
{
    chunk = Resources::GetSound(file);
}

Sound::~Sound()
{
    if (chunk != nullptr)
    {
        Stop();
    }
}

bool Sound::IsOpen()
{
    if (chunk == nullptr)
    {
        return false;
    }

    return true;
}

void Sound::Update(float dt) {}

void Sound::Render() {}

bool Sound::Is(string type)
{
    if (type == "Sound")
    {
        return true;
    }
    return false;
}