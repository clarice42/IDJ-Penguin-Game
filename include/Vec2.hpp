#ifndef VEC2_HPP
#define VEC2_HPP

#include <iostream>
#include <math.h>

using namespace std;

class Vec2
{
public:
    float x, y;
    Vec2();
    Vec2(float, float);
    Vec2 GetRotated(float);
    friend Vec2 operator+(const Vec2 &, const Vec2 &);
};

#endif