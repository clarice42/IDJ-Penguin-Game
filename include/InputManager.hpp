#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <iostream>

using namespace std;

class InputManager {
    private:
    bool mouseState[6];
    int mouseUpdate[6];
    bool quitRequested;
    int updateCounter, mouseX, mouseY;

    public:
    InputManager();
    ~InputManager();
    void Update();
    bool KeyPress(int);
    bool KeyRelease(int);
    bool IsMouseDown(int);
    int GetMouseX();
    int GetMouseY();
    bool QuitRequested();
    InputManager& GetInstance();
};

#endif