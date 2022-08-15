#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <iostream>
#include <unordered_map>
#define INCLUDE_SDL
#include "SDL_include.hpp"

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT 
#define UP_ARROW_KEY SDLK_UP 
#define DOWN_ARROW_KEY SDLK_DOWN 
#define ESCAPE_KEY SDLK_ESCAPE 
#define SPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

using namespace std;

class InputManager {
    private:
    bool mouseState[6];
    int mouseUpdate[6];
    unordered_map<int, bool> keyState;
    unordered_map<int, int> keyUpdate;
    bool quitRequested;
    int updateCounter, mouseX, mouseY;

    public:
    InputManager();
    ~InputManager();
    void Update();
    bool KeyPress(int);
    bool KeyRelease(int);
    bool IsKeyDown(int);
    bool MousePress(int);
    bool MouseRelease(int);
    bool IsMouseDown(int);
    int GetMouseX();
    int GetMouseY();
    bool QuitRequested();
    static InputManager& GetInstance();
};

#endif