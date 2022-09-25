#ifndef MINION_HPP
#define MINION_HPP

#include <iostream>
#include "GameObject.hpp"

#define VELOCIDADE_ANGULAR 4.188790205
#define PI 3.14159265359
#define RADIUS 200

using namespace std;

class Minion : public Component
{
private:
    weak_ptr<GameObject> alienCenter;
    float arc;

public:
    Minion(GameObject &, weak_ptr<GameObject>, float);
    void Update(float);
    void Render();
    bool Is(string);
    void Shoot(Vec2);
    void Start(){};
};

#endif