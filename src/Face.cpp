#include "Face.hpp"

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
}

void Face::Damage(int damage)
{
    Sound *sound = (Sound *)associated.GetComponent("Sound");

    if (hitpoints >= 0)
    {
        hitpoints -= damage;
    }
    else
    {
        associated.RequestDelete();
        if (sound != nullptr)
        {
            sound->Play();
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