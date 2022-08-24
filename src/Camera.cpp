#include "Camera.hpp"
#include "InputManager.hpp"

Vec2 Camera::pos(0, 0);
Vec2 Camera::speed(50, 50);

void Camera::Follow(GameObject *newFocus)
{
    focus = newFocus;
}

void Camera::Unfollow()
{
    focus = nullptr;
}

void Camera::Update(float dt)
{
    InputManager input = InputManager::GetInstance();

    if (input.IsKeyDown(LEFT_ARROW_KEY))
    {
        pos.x = pos.x - (dt * speed.x);
    }
    if (input.IsKeyDown(RIGHT_ARROW_KEY))
    {
        pos.x = pos.x + (dt * speed.x);
    }
    if (input.IsKeyDown(UP_ARROW_KEY))
    {
        pos.y = pos.y - (dt * speed.y);
    }
    if (input.IsKeyDown(DOWN_ARROW_KEY))
    {
        pos.y = pos.y + (dt * speed.y);
    }
}