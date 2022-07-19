#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <iostream>
#include <vector>
#include "Component.hpp"
#include "TileSet.hpp"

using namespace std;

class TileMap : public Component {
    private:
    vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;

    public:
    TileMap(GameObject&, string, TileSet*);
    void Load(string);
    void SetTileSet(TileSet*);
    int& At(int, int, int z = 0);
    void Render();
    void RenderLayer(int, int cameraX = 0, int cameraY = 0);
    int GetWidth();
    int GetHeight();
    int GetDepth();
    void Update(float);
    bool Is(string);
};

#endif