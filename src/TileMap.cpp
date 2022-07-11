#include "TileMap.hpp"

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated) {
    Load(file);
    SetTileSet(tileSet);
}

void TileMap::Load(string file) {
    vector<int> tiles = [];
    int x = 0, y = 0, z = 0, index = 0;

    for(vector<int>::size_type i = 0; i < x; i++) {
        for(vector<int>::size_type j = 0; j < y; j++) {
            for(vector<int>::size_type k = 0; k < z; k++) {
                tileMatrix[index] = tiles[i][j][k] - 1;
                index++;
            }
        }
    }
}

void TileMap::SetTileSet(TileSet* tileSetRec) {
    tileSet = tileSetRec;
}

int& TileMap::At(int x, int y, int z) {
    for(vector<int>::size_type i = 0; i < tileMatrix.size(); i++) {
        if(x < mapWidth) {
            
        }
    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {

}

void TileMap::Render() {

}

int TileMap::GetWidth() {
    return mapWidth;
}

int TileMap::GetHeight() {
    return mapHeight;
}

int TileMap::GetDepth() {
    return mapDepth;
}