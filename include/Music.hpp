#ifndef MUSIC_HPP
#define MUSIC_HPP
#endif

#define INCLUDE_SDL_MIXER
#include "SDL_include.hpp"
#include <iostream>

using namespace std;

class Music
{
private:
    Mix_Music *music;

public:
    Music();
    Music(string);
    ~Music();
    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(string);
    bool IsOpen();
};