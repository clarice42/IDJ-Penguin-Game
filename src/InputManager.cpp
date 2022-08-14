#include "InputManager.hpp"

InputManager &InputManager::GetInstance()
{
    static InputManager inputManager;
    return inputManager;
}

InputManager::InputManager()
{
    mouseState[6] = {};
    mouseUpdate[6] = {};
    quitRequested = false;
    updateCounter = 0;
    mouseX = 0;
    mouseY = 0;
}

void InputManager::Update()
{
    SDL_Event event;
    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;
    updateCounter++;

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event))
    {

        // Se o evento for quit, setar a flag para terminação
        if (event.type == SDL_QUIT)
        {
            quitRequested = true;
        }

        // Se o evento for clique...
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int buttonType = event.button.button;
            mouseState[buttonType] = true;
            mouseUpdate[buttonType] = updateCounter;
        }
        if (event.type == SDL_MOUSEBUTTONUP)
        {
            int buttonType = event.button.button;
            mouseState[buttonType] = false;
            mouseUpdate[buttonType] = updateCounter;
        }
        if (event.type == SDL_KEYDOWN)
        {
            if (!event.key.repeat)
            {
                int keyType = event.key.keysym.sym;
                keyState[keyType] = true;
                keyUpdate[keyType] = updateCounter;
            }
        }
        if (event.type == SDL_KEYUP)
        {
            if (!event.key.repeat)
            {
                int keyType = event.key.keysym.sym;
                keyState[keyType] = false;
                keyUpdate[keyType] = updateCounter;
            }
        }
    }
}

bool InputManager::KeyPress(int key)
{
    return (updateCounter == keyUpdate[key]) && keyState[key];
}

bool InputManager::KeyRelease(int key)
{
    return (updateCounter == keyUpdate[key]) && !keyState[key];
}

bool InputManager::IsKeyDown(int key)
{
    return keyState[key];
}

bool InputManager::MousePress(int button)
{
    return (updateCounter == mouseUpdate[button]) && mouseState[button];
}

bool InputManager::MouseRelease(int button)
{
    return (updateCounter == mouseUpdate[button]) && !mouseState[button];
}

bool InputManager::IsMouseDown(int button)
{
    return mouseState[button];
}

int InputManager::GetMouseX()
{
    return mouseX;
}

int InputManager::GetMouseY()
{
    return mouseY;
}

bool InputManager::QuitRequested()
{
    return quitRequested;
}

InputManager::~InputManager() {}