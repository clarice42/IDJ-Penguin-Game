#ifndef RECT_HPP
#define RECT_HPP

#include <iostream>
#include "Vec2.hpp"

using namespace std;

class Rect
{
public:
    float x, y, w, h;
    Rect();
    Rect(float, float, float, float);
    bool Contains(Vec2);
};

#endif