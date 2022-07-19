#include "State.hpp"
#include "TileMap.hpp"
#include "TileSet.hpp"

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
    Input();

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

void State::Input()
{
    SDL_Event event;
    int mouseX, mouseY;

    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event))
    {

        // Se o evento for quit, setar a flag para terminação
        if (event.type == SDL_QUIT)
        {
            quitRequested = true;
        }

        // Se o evento for clique...
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {

            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for (int i = objectArray.size() - 1; i >= 0; --i)
            {
                // Obtem o ponteiro e casta pra Face.
                GameObject *go = (GameObject *)objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.

                if (go->box.Contains({(float)mouseX, (float)mouseY}))
                {
                    Face *face = (Face *)go->GetComponent("Face");
                    if (nullptr != face)
                    {
                        // Aplica dano
                        face->Damage(std::rand() % 10 + 10);
                        // Sai do loop (só queremos acertar um)
                        break;
                    }
                }
            }
        }
        if (event.type == SDL_KEYDOWN)
        {
            // Se a tecla for ESC, setar a flag de quit
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                quitRequested = true;
            }
            // Se não, crie um objeto
            else
            {
                Vec2 objPos = Vec2(200, 0).GetRotated((-PI + PI * (rand() % 1001) / 500.0)) + Vec2(mouseX, mouseY);
                AddObject((int)objPos.x, (int)objPos.y);
            }
        }
    }
}

void State::AddObject(int mouseX, int mouseY)
{
    GameObject *penguin = new GameObject();

    Sprite *penguin_face = new Sprite(PENGUIN_FACE, *penguin);
    penguin->AddComponent(penguin_face);

    penguin->box.x = mouseX;
    penguin->box.y = mouseY;
    penguin->box.w = penguin_face->GetWidth();
    penguin->box.h = penguin_face->GetHeight();

    Sound *explosion = new Sound(*penguin, EXPLOSION_SOUND);
    penguin->AddComponent(explosion);

    Face *enemy = new Face(*penguin);
    penguin->AddComponent(enemy);

    objectArray.emplace_back(penguin);
}