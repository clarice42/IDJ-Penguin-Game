#ifndef CAMERA_FOLLOWER_HPP
#define CAMERA_FOLLOWER_HPP

#include <iostream>
#include "GameObject.hpp"

using namespace std;

class CameraFollower : public Component
{
public:
    CameraFollower(GameObject &);
    void Update(float);
    void Render();
    bool Is(string);
};

#endif