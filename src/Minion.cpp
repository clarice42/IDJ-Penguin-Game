#include "Minion.hpp"
#include "Sprite.hpp"

Minion::Minion(GameObject &associated, weak_ptr<GameObject> recAlienCenter, float arcOffSetDeg) : Component(associated)
{
    Sprite *minionSprite = new Sprite("assets/minion.png", associated);
    associated.AddComponent(minionSprite);

    alienCenter = recAlienCenter;
    arc = arcOffSetDeg;
}

void Minion::Update(float dt)
{
    arc += VELOCIDADE_ANGULAR;
    shared_ptr<GameObject> sharedAlienCenter = alienCenter.lock();

    associated.box.x = cos((arc * PI) / 180) * RADIUS + sharedAlienCenter->box.x;
    associated.box.y = sin((arc * PI) / 180) * RADIUS + sharedAlienCenter->box.y;

    if (!sharedAlienCenter)
    {
        associated.RequestDelete();
    }
}

void Minion::Render() {}

bool Minion::Is(string type)
{
    return type == "Minion";
}

void Minion::Shoot(Vec2 pos) {}