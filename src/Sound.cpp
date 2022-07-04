#include "Sound.hpp"

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
    chunk = Mix_LoadWAV(file.c_str());

    if (chunk == nullptr)
    {
        printf("Could not open file: %s\n", SDL_GetError());
    }
}

Sound::~Sound()
{
    if (chunk != nullptr)
    {
        Stop();
        Mix_FreeChunk(chunk);
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