#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "Component.hpp"
#include "Rect.hpp"

using namespace std;

class GameObject
{
private:
    vector<unique_ptr<Component>> components;
    bool isDead;
    bool started;

public:
    GameObject();
    ~GameObject();
    void Update(float);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component *);
    void RemoveComponent(Component *);
    void Start();
    Component *GetComponent(string);
    Rect box;
    double angleDeg;
};

#endif