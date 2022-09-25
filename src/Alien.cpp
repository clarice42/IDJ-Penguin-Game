#include "Alien.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"

Alien::Alien(GameObject &associated, int nMinions) : Component(associated)
{
    Sprite *spriteComp = new Sprite("assets/alien.png", associated);
    associated.AddComponent(spriteComp);

    speed.x = 20;
    speed.y = 20;
    hp = 30;
    nMinions = nMinions;
}

Alien::~Alien()
{
    minionArray.clear();
}

void Alien::Update(float dt)
{
    InputManager input = InputManager::GetInstance();

    if (input.MousePress(LEFT_MOUSE_BUTTON))
    {
        Action action = Action(Action::SHOOT, input.GetMouseX() + Camera::pos.x, input.GetMouseY() + Camera::pos.y);
        taskQueue.push(action);
    }

    if (input.MousePress(RIGHT_MOUSE_BUTTON))
    {
        Action action = Action(Action::MOVE, input.GetMouseX() + Camera::pos.x, input.GetMouseY() + Camera::pos.y);
        taskQueue.push(action);
    }

    if (taskQueue.size() > 0)
    {
        Action task = taskQueue.front();

        if (task.type == Action::MOVE)
        {
            float angle = atan2(task.pos.y - associated.box.y, task.pos.x - associated.box.x);
            float dx = speed.x * cos(angle) * dt;
            float dy = speed.y * sin(angle) * dt;

            bool isInsideWidth = abs(associated.box.x - task.pos.x) < dx;
            bool isInsideHeight = abs(associated.box.y - task.pos.y) < dy;

            if (isInsideWidth || isInsideHeight)
            {
                associated.box.x = task.pos.x;
                associated.box.y = task.pos.y;

                taskQueue.pop();
            }
            else
            {
                associated.box.x += dx;
                associated.box.y += dy;
            }
        }
        else if (task.type == Action::SHOOT)
        {
            taskQueue.pop();
        }
    }

    if (hp <= 0)
    {
        associated.RequestDelete();
    }
}

Alien::Action::Action(ActionType rectype, float x, float y)
{
    type = rectype;
    pos.x = x;
    pos.y = y;
}

void Alien::Render() {}

bool Alien::Is(string type)
{
    return type == "Alien";
}