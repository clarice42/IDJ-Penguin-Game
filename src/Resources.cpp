#include "Resources.hpp"
#include "Game.hpp"

unordered_map<std::string, SDL_Texture *> Resources::imageTable;
unordered_map<std::string, Mix_Music *> Resources::musicTable;
unordered_map<std::string, Mix_Chunk *> Resources::soundTable;

SDL_Texture *Resources::GetImage(string file)
{
    if (imageTable.count(file) == 0)
    {
        SDL_Texture *texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
        imageTable.emplace(file, texture);

        if (texture == nullptr)
        {
            printf("Could not get image: %s\n", SDL_GetError());
        }
    }

    return imageTable[file];
}

void Resources::ClearImages()
{
    for (auto i = imageTable.begin(); i != imageTable.end(); i++)
    {
        SDL_DestroyTexture(i->second);
    }

    imageTable.clear();
}

Mix_Music *Resources::GetMusic(string file)
{
    if (musicTable.count(file) == 0)
    {
        Mix_Music *music = Mix_LoadMUS(file.c_str());
        musicTable.emplace(file, music);

        if (music == nullptr)
        {
            printf("Could not get music: %s\n", SDL_GetError());
        }
    }

    return musicTable[file];
}

void Resources::ClearMusics()
{
    for (auto i = musicTable.begin(); i != musicTable.end(); i++)
    {
        Mix_FreeMusic(i->second);
    }

    musicTable.clear();
}

Mix_Chunk *Resources::GetSound(string file)
{
    if (soundTable.count(file) == 0)
    {
        Mix_Chunk *sound = Mix_LoadWAV(file.c_str());
        soundTable.emplace(file, sound);

        if (sound == nullptr)
        {
            printf("Could not get sound: %s\n", SDL_GetError());
        }
    }

    return soundTable[file];
}

void Resources::ClearSounds()
{
    for (auto i = soundTable.begin(); i != soundTable.end(); i++)
    {
        Mix_FreeChunk(i->second);
    }

    soundTable.clear();
}