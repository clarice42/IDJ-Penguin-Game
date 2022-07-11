#include "TileMap.hpp"

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated) {
    Load(file);
    SetTileSet(tileSet);
}

void TileMap::Load(string file) {
    
}

void TileMap::SetTileSet(TileSet* tileSetRec) {
    tileSet = tileSetRec;
}

int& TileMap::At(int x, int y, int z) {
    for(vector<int>::size_type i = 0; i < tileMatrix.size(); i++) {

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