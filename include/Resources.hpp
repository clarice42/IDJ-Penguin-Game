#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <iostream>
#include <unordered_map>

using namespace std;

class Resources {
    private:
    unordered_map<string, SDL_Texture*> imageTable;
    unordered_map<string, Mix_Music*> musicTable;
    unordered_map<string, Mix_Chunk*> soundTable;

    public:
    static SDL_Texture* GetImage(string);
    void ClearImages();
    Mix_Music* GetMusic(string);
    void ClearMusics();
    Mix_Chunk* GetSound(string);
    void ClearSounds();
};

#endif