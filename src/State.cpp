#include "State.hpp"
#include "TileMap.hpp"
#include "TileSet.hpp"
#include "InputManager.hpp"
#include "Camera.hpp"
#include "CameraFollower.hpp"

State::State()
{
    quitRequested = false;
    GameObject *background_image = new GameObject();

    bg = new Sprite(BACKGROUND_PATH, *background_image);
    background_image->AddComponent(bg);

    background_image->box.x = 0;
    background_image->box.y = 0;
    background_image->box.w = bg->GetWidth();
    background_image->box.h = bg->GetHeight();

    CameraFollower *cameraFollower = new CameraFollower(*background_image);
    background_image->AddComponent(cameraFollower);

    objectArray.emplace_back(background_image);

    GameObject *map = new GameObject();

    TileSet *tileset = new TileSet(64, 64, TILESET_PATH);
    TileMap *tileMap = new TileMap(*map, TILEMAP_PATH, tileset);
    map->AddComponent(tileMap);

    map->box.x = 0;
    map->box.y = 0;

    objectArray.emplace_back(map);

    LoadAssets();
    music.Play();
}

State::~State()
{
    objectArray.clear();
}

void State::LoadAssets()
{
    music = *new Music(MUSIC_PATH);
    music.Open(MUSIC_PATH);
}

void State::Update(float dt)
{
    InputManager input = InputManager::GetInstance();
    Camera::Update(dt);

    if (input.KeyPress(ESCAPE_KEY) || input.QuitRequested())
    {
        quitRequested = true;
    }

    if (input.KeyPress(SPACE_KEY))
    {

        Vec2 objPos = Vec2(200, 0).GetRotated((-PI + PI * (rand() % 1001) / 500.0)) + Vec2(input.GetMouseX(), input.GetMouseY());
        AddObject((int)objPos.x + Camera::pos.x, (int)objPos.y + Camera::pos.y);
    }

    for (vector<int>::size_type i = 0; i < objectArray.size(); i++)
    {
        objectArray[i]->Update(dt);
    }

    for (vector<int>::size_type i = 0; i < objectArray.size(); i++)
    {
        if (objectArray[i]->IsDead())
        {
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render()
{
    for (vector<int>::size_type i = 0; i < objectArray.size(); i++)
    {
        objectArray[i]->Render();
    }
}

bool State::QuitRequested()
{
    return quitRequested;
}

void State::AddObject(int mouseX, int mouseY)
{
    GameObject *penguin = new GameObject();

    Sprite *penguin_face = new Sprite(PENGUIN_FACE, *penguin);
    penguin->AddComponent(penguin_face);

    penguin->box.x = mouseX - (penguin_face->GetWidth() / 2);
    penguin->box.y = mouseY - (penguin_face->GetHeight() / 2);
    penguin->box.w = penguin_face->GetWidth();
    penguin->box.h = penguin_face->GetHeight();

    Sound *explosion = new Sound(*penguin, EXPLOSION_SOUND);
    penguin->AddComponent(explosion);

    Face *enemy = new Face(*penguin);
    penguin->AddComponent(enemy);

    objectArray.emplace_back(penguin);
}