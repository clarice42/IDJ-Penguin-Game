#include "TileSet.hpp"
#include "GameObject.hpp"

TileSet::TileSet(int width, int height, string file) : tileSet(*new GameObject)
{
  tileWidth = width;
  tileHeight = height;
  tileSet.Open(file);
  rows = tileSet.GetWidth() / tileWidth;
  columns = tileSet.GetHeight() / tileHeight;
}

void TileSet::RenderTile(unsigned int index, float x, float y)
{
  unsigned int numberOfTiles = rows * columns;
  if (index <= numberOfTiles)
  {
    tileSet.SetClip(x, y, tileWidth, tileHeight);
    tileSet.Render(x, y);
  }
}

int TileSet::GetTileWidth()
{
  return tileWidth;
}

int TileSet::GetTileHeight()
{
  return tileHeight;
}