#include "Alien.hpp"
#include "Sprite.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include "Minion.hpp"
#include "Game.hpp"

Alien::Alien(GameObject &associated, int numMinions) : Component(associated)
{
    Sprite *alienSprite = new Sprite("assets/alien.png", associated);
    associated.AddComponent(alienSprite);

    speed.x = 20;
    speed.y = 20;
    hp = 30;
    nMinions = numMinions;
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
            Minion *minion = (Minion *)minionArray[rand() % minionArray.size()].lock().get()->GetComponent("Minion");
            minion->Shoot(task.pos);
            taskQueue.pop();
        }
    }

    if (hp <= 0)
    {
        associated.RequestDelete();
    }
}

Alien::Action::Action(ActionType typeReceived, float x, float y)
{
    type = typeReceived;
    pos.x = x;
    pos.y = y;
}

void Alien::Render() {}

bool Alien::Is(string type)
{
    return type == "Alien";
}

void Alien::Start()
{
    weak_ptr<GameObject> alienCenter = Game::GetInstance().GetState().GetOjectPtr(&associated);

    for (int i = 0; i < nMinions; i++)
    {
        GameObject *minionGo = new GameObject();
        Minion *minion = new Minion(*minionGo, alienCenter, (360 / nMinions) * i);
        minionGo->AddComponent(minion);

        minionArray.emplace_back(Game::GetInstance().GetState().AddObject(minionGo));
    }
}