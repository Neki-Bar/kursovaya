#ifndef TILE_H
#define TILE_H



struct Tile {

    enum fighterType{
        flag,
        spy,
        scout,
        miner,
        sergeant,
        lieutenant,
        captain,
        major,
        colonel,
        general,
        marshal,
        bomb
    };

    fighterType role;

    int count;

    bool isvoidCell;
    bool isvoidTile;

    bool ismy;
    bool isalien;

    bool choosed = false;
    Tile();
    Tile (bool voidCell);
    Tile (int role, int count);

    Tile(int role, bool isvoidCell,
         bool isvoidTile,
         bool ismy, bool isalien);

    Tile& operator =(const Tile& tile)
    {
        this->role = tile.role;
        this->isvoidCell = tile.isvoidCell;
        this->isvoidTile =tile.isvoidTile;
        this->ismy = tile.ismy;
        this->isalien = tile.isalien;
        this->count = tile.count;
        return *this;
    }

    Tile(const Tile& tile);

};

#endif //TILE_H
