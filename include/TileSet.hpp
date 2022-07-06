#ifndef TILESET_HPP
#define TILESET_HPP

#include <iostream>
#include "Sprite.hpp"

using namespace std;

class TileSet {
  private:
  Sprite tileSet;
  int rows;
  int columns;
  int tileWidth;
  int tileHeight;
  
  public:
  TitleSet(int, int, string);
  void RenderTile(unsigned, float, float);
  int GetTileWidth();
  int GetTileHeight();
};

#endif
