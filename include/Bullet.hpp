#ifndef BULLET_HPP
#define BULLET_HPP

#include <iostream>
#include "GameObject.hpp"

using namespace std;

class Bullet : public Component
{
private:
    Vec2 speed;
    float distanceLeft;
    int damage;

public:
    Bullet(GameObject &, float, float, int, float, string);
    void Update(float);
    void Render();
    bool Is(string);
    void Start(){};
    int GetDamage();
};

#endif