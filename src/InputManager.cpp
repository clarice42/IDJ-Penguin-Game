#include "InputManager.hpp"

InputManager& InputManager::GetInstance() {
    static InputManager inputManager;
    return inputManager;
}

InputManager::InputManager() {
    
}