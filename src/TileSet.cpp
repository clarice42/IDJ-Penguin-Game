#include "TileSet.hpp"
#include "GameObject.hpp"

TileSet::TileSet(int width, int height, string file) : tileSet(*new GameObject)
{
  tileWidth = width;
  tileHeight = height;
  tileSet.Open(file);
  rows = tileSet.GetHeight() / tileHeight;
  columns = tileSet.GetWidth() / tileWidth;
}

void TileSet::RenderTile(unsigned int index, float x, float y)
{
  unsigned int numberOfTiles = (rows * columns) - 1;
  if (index <= numberOfTiles)
  {
    int x_aux = tileWidth * (index % columns);
    int y_aux = tileHeight * (index / columns);
    tileSet.SetClip(x_aux, y_aux, tileWidth, tileHeight);
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