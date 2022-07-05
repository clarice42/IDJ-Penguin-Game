#include "Rect.hpp"

Rect::Rect()
{
    x = 0.0;
    y = 0.0;
    w = 0.0;
    h = 0.0;
}

Rect::Rect(float x_rec, float y_rec, float w_rec, float h_rec)
{
    x = x_rec;
    y = y_rec;
    w = w_rec;
    h = h_rec;
}

bool Rect::Contains(Vec2 point)
{
    bool isInsideWidth = point.x >= x && point.x <= (w + x);
    bool isInsideHeight = point.y >= y && point.y <= (h + y);
    return isInsideWidth && isInsideHeight;
}