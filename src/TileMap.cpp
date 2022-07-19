#include "TileMap.hpp"
#include "Game.hpp"
#include <fstream>

TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet) : Component(associated)
{
    Load(file);
    SetTileSet(tileSet);
}

void TileMap::Load(string file)
{
    ifstream fileStream(file);

    if (fileStream.is_open())
    {
        char comma;
        fileStream >> mapWidth >> comma >> mapHeight >> comma >> mapDepth >> comma;
        int matrix_value;
        while (fileStream >> matrix_value)
        {
            tileMatrix.push_back(matrix_value - 1);
            fileStream >> comma;
        }
    }

    fileStream.close();
}

void TileMap::SetTileSet(TileSet *tileSet_aux)
{
    tileSet = tileSet_aux;
}

int &TileMap::At(int x, int y, int z)
{
    int index = x + (mapWidth * y) + (mapWidth * mapHeight * z);
    return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
    for (int i = 0; i < mapWidth; i++)
    {
        for (int j = 0; j < mapHeight; j++)
        {
            int x_position = i * tileSet->GetTileWidth() - cameraX;
            int y_position = j * tileSet->GetTileHeight() - cameraY;
            int index = At(i, j, layer);
            tileSet->RenderTile(index, x_position, y_position);
        }
    }
}

void TileMap::Render()
{
    for (int i = 0; i < mapDepth; i++)
    {
        RenderLayer(i, associated.box.x, associated.box.y);
    }
}

int TileMap::GetWidth()
{
    return mapWidth;
}

int TileMap::GetHeight()
{
    return mapHeight;
}

int TileMap::GetDepth()
{
    return mapDepth;
}

void TileMap::Update(float dt) {}

bool TileMap::Is(string type)
{
    if (type == "TileMap")
    {
        return true;
    }
    return false;
}