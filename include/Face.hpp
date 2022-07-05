#ifndef FACE_HPP
#define FACE_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include "GameObject.hpp"
#include "Sound.hpp"

using namespace std;

class Face : public Component
{
private:
    int hitpoints;

public:
    Face(GameObject &);
    void Damage(int);
    void Update(float);
    void Render();
    bool Is(string);
};

#endif