#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.hpp"
#include <iostream>
#include <unordered_map>

using namespace std;

class Resources {
    private:
    static unordered_map<string, SDL_Texture*> imageTable;
    static unordered_map<string, Mix_Music*> musicTable;
    static unordered_map<string, Mix_Chunk*> soundTable;

    public:
    static SDL_Texture* GetImage(string);
    static void ClearImages();
    static Mix_Music* GetMusic(string);
    static void ClearMusics();
    static Mix_Chunk* GetSound(string);
    static void ClearSounds();
};

#endif