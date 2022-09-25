#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <iostream>
#include <queue>
#include "GameObject.hpp"

using namespace std;

class Alien : public Component
{
private:
    class Action
    {
    public:
        enum ActionType
        {
            MOVE,
            SHOOT
        };
        Action(ActionType, float, float);
        ActionType type;
        Vec2 pos;
    };
    Vec2 speed;
    int hp;
    int nMinions;
    queue<Action> taskQueue;
    vector<weak_ptr<GameObject>> minionArray;

public:
    Alien(GameObject &, int);
    ~Alien();
    void Update(float);
    void Render();
    bool Is(string);
    void Start();
};

#endif