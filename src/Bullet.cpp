#include "Bullet.hpp"
#include "Sprite.hpp"

Bullet::Bullet(GameObject &associated, float angle, float recSpeed, int recDamage, float maxDistance, string sprite) : Component(associated)
{
    Sprite *bulletSprite = new Sprite(sprite, associated);
    associated.angleDeg = angle * 180 / PI;
    associated.AddComponent(bulletSprite);

    speed.x = recSpeed * cos(angle);
    speed.y = recSpeed * sin(angle);

    distanceLeft = maxDistance;
    damage = recDamage;
}

void Bullet::Update(float dt)
{
    associated.box.x += speed.x * dt;
    associated.box.y += speed.y * dt;

    float absSpeed = sqrt((speed.x * speed.x) + (speed.y * speed.y));
    distanceLeft -= absSpeed * dt;

    if (distanceLeft <= 0)
    {
        associated.RequestDelete();
    }
}

void Bullet::Render() {}

bool Bullet::Is(string type)
{
    return type == "Bullet";
}

int Bullet::GetDamage()
{
    return damage;
}