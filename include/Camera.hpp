#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include "GameObject.hpp"
#include "Vec2.hpp"

using namespace std;

class Camera
{
private:
    GameObject *focus;

public:
    static Vec2 pos;
    static Vec2 speed;
    void Follow(GameObject *);
    void Unfollow();
    static void Update(float);
};

#endif