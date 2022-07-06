#include "TileSet.hpp"

TileSet::TileSet(int width, int height, string file) {
  tileWidth = width;
  tileHeight = height;
  tileSet = *new Sprite();
  tileSet.Open(file);
  
  if(tileSet != nullptr) {
    rows = tileSet.width / tileWidth;
    columns = tileSet.height / tileHeight;
  }
}

void TileSet::RenderTile(unsigned index, float x, float y) {
    int numberOfTiles = tileWidth * tileHeight - 1;
    if(index >= 0 && index <= numberOfTiles) {
        tileSet->SetClip(x, y, tileWidth, tileHeight);
        tileSet->Render(x, y);
    }
}

int TileSet::GetTileWidth() {
    return tileWidth;
}

int TileSet::GetTileHeight() {
    return tileHeight;
}