#include "Face.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
    originalPos.x = associated.box.x;
    originalPos.y = associated.box.y;
}

void Face::Damage(int damage)
{
    hitpoints -= damage;

    if (hitpoints <= 0)
    {
        Sound *sound = (Sound *)associated.GetComponent("Sound");
        if (sound != nullptr)
        {
            sound->Play();
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
        associated.RequestDelete();
    }
}

void Face::Update(float dt)
{
    InputManager input = InputManager::GetInstance();

    for (int i = 0; i < 6; i++)
    {
        if (input.MousePress(i) && associated.box.Contains({(float)input.GetMouseX(), (float)input.GetMouseY()}))
        {
            // Aplica dano
            Damage(std::rand() % 10 + 10);
            // Sai do loop (só queremos acertar um)
            break;
        }
    }
}

void Face::Render()
{
    associated.box.x = originalPos.x + Camera::pos.x;
    associated.box.y = originalPos.y + Camera::pos.y;
}

bool Face::Is(string type)
{
    if (type == "Face")
    {
        return true;
    }

    return false;
}