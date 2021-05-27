
#include <tile.h>
Tile::Tile()
{
    isvoidTile = true;
}

Tile::Tile(bool voidCell)
{
    isvoidCell = voidCell;
}

Tile::Tile(int role, int count): role(static_cast<fighterType>(role)),
    count(count){}

Tile::Tile(int role, bool isvoidCell, bool isvoidTile, bool ismy, bool isalien): role(static_cast<fighterType>(role)),
    isvoidCell(isvoidCell),
    isvoidTile(isvoidTile),
    ismy(ismy),
    isalien(isalien){}


Tile::Tile(const Tile &tile)
{
    this->role = tile.role;
    this->isvoidCell = tile.isvoidCell;
    this->isvoidTile =tile.isvoidTile;
    this->ismy = tile.ismy;
    this->isalien = tile.isalien;
    this->count = tile.count;
}


