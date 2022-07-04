#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <iostream>
#include <vector>
#include "Component.hpp"
#include "Rect.hpp"

using namespace std;

class GameObject
{
private:
    vector<Component *> components;
    bool isDead;

public:
    GameObject();
    ~GameObject();
    void Update(float);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component *);
    void RemoveComponent(Component *);
    Component *GetComponent(string);
    Rect box;
};

#endif