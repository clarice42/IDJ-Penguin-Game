#include "Face.hpp"

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

void Face::Update(float dt) {}

void Face::Render() {}

bool Face::Is(string type)
{
    if (type == "Face")
    {
        return true;
    }

    return false;
}