#ifndef SOUND_HPP
#define SOUND_HPP

#define INCLUDE_SDL_MIXER
#include "SDL_include.hpp"
#include "Component.hpp"
#include <iostream>

using namespace std;

class Sound : public Component
{
private:
    Mix_Chunk *chunk;
    int channel;

public:
    Sound(GameObject &);
    Sound(GameObject &, string);
    ~Sound();
    void Play(int times = 1);
    void Stop();
    void Open(string);
    bool IsOpen();
    void Update(float);
    void Render();
    bool Is(string);
};

#endif