#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.hpp"
#include "Game.hpp"
#include "Resources.hpp"
#include "InputManager.hpp"

Game *Game::instance = nullptr;

Game &Game::GetInstance()
{
    if (instance == nullptr)
    {
        new Game(GAME_TITLE, GAME_WIDTH, GAME_HEIGHT);
    }
    return *instance;
}

Game::Game(string title, int width, int height)
{
    if (instance != nullptr)
    {
        throw invalid_argument("There is already an instance of the game!");
    }

    instance = this;

    // SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }

    // Imagem
    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
    {
        SDL_Log("Unable to initialize image library: %s", SDL_GetError());
    }

    // Som
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,
                      MIX_DEFAULT_FORMAT,
                      MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
        SDL_Log("Unable to initialize audio library: %s", SDL_GetError());
    }

    if (Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) == 0)
    {
        SDL_Log("Unable to initialize sound library: %s", SDL_GetError());
    }

    if (!Mix_AllocateChannels(32))
    {
        SDL_Log("Unable to allocate channels: %s", SDL_GetError());
    }

    // Janela
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (window == nullptr)
    {
        printf("Could not create a window: %s\n", SDL_GetError());
    }

    // Renderizador para a janela
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        printf("Could not create a renderer: %s\n", SDL_GetError());
    }

    state = new State();

    srand(time(NULL));

    frameStart = 0;
    dt = 0.0;
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer *Game::GetRenderer()
{
    return renderer;
}

State &Game::GetState()
{
    return *state;
}

void Game::Run()
{
    while (!state->QuitRequested())
    {
        CalculateDeltaTime();
        InputManager::GetInstance().Update();
        state->Update(1.0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }

    state->~State();
    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}

void Game::CalculateDeltaTime()
{
    int frameEnd = SDL_GetTicks();
    float frameDif = (float)(frameEnd - frameStart);
    dt = frameDif / 1000;
    frameStart = frameEnd;
}

float Game::GetDeltaTime()
{
    return dt;
}