#include "Face.hpp"
#include "InputManager.hpp"

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
}

void Face::Damage(int damage)
{
    Sound *sound = (Sound *)associated.GetComponent("Sound");
    hitpoints -= damage;

    if (hitpoints <= 0)
    {
        associated.RequestDelete();
        if (sound != nullptr)
        {
            sound->Play();
            std::this_thread::sleep_for(std::chrono::milliseconds(700));
        }
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

void Face::Render() {}

bool Face::Is(string type)
{
    if (type == "Face")
    {
        return true;
    }

    return false;
}