#include "Minion.hpp"
#include "Sprite.hpp"
#include "Bullet.hpp"
#include "Camera.hpp"
#include "Game.hpp"

Minion::Minion(GameObject &associated, weak_ptr<GameObject> recAlienCenter, float arcOffSetDeg) : Component(associated)
{
    Sprite *minionSprite = new Sprite("assets/minion.png", associated);
    
    associated.angleDeg = arcOffSetDeg;
    double scale = 1 + (random() % 6) % 10;
    minionSprite->SetScale(scale, scale);

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

void Minion::Shoot(Vec2 pos)
{
    float angle = atan2(pos.y + Camera::pos.y, pos.x + Camera::pos.x);

    GameObject *bulletGo = new GameObject();
    bulletGo->box.x = associated.box.x;
    bulletGo->box.y = associated.box.y;

    Bullet *bullet = new Bullet(*bulletGo, angle, 8, 10, 500, "assets/minionbullet1.png");
    bulletGo->AddComponent(bullet);

    Game::GetInstance().GetState().AddObject(bulletGo);
}