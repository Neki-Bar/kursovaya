#include "fieldmodel.h"
#include<QModelIndex>


enum TileState{
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
    bomb,
    notvoidCell = 0,
    voidCell,
    notvoidTile = 0,
    voidTile,
    notMy = 0,
    my,
    notAlien = 0,
    alien
};


FieldModel::FieldModel(int size, int dim = 10): DIMENSION(dim), FIELD_SIZE(size)
{

    if(size == 100){
        field = std::vector<Tile>(100);
        setVoidCell(this->field);
        for (int i = 0; i < 40; ++i){
            field[i] =  Tile(TileState::flag,
                        TileState::notvoidCell,
                        TileState::notvoidTile,
                        TileState::notMy,
                        TileState::alien);
        }
    }

    else if (size == 40) field = std::vector<Tile>(size);
}

FieldModel &FieldModel::operator =(FieldModel &model)
{
    this->DIMENSION = model.DIMENSION;

}


int FieldModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return FIELD_SIZE;
}

QVariant FieldModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return {};
    int listIndex = index.row();
    if (role == RangRole) return getText(listIndex);
    if (role == VoidCellRole) return QVariant(field[listIndex].isvoidCell);
    if (role == VoidTileRole) return QVariant(field[listIndex].isvoidTile);
    if (role == IsMyRole) return QVariant(field[listIndex].ismy);
    if (role == IsAlienRole) return QVariant(field[listIndex].isalien);
    return {};
}

QHash<int, QByteArray> FieldModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RangRole] = "rang";
    roles[VoidCellRole] = "voidcell";
    roles[VoidTileRole] = "voidtile";
    roles[IsMyRole] = "ismy";
    roles[IsAlienRole] = "isalien";



    return roles;
}

void FieldModel::setVoidCell(std::vector<Tile>& field)
{
    Tile temp = Tile(true);
    field[42] = temp;
    field[43] = temp;
    field[46] = temp;
    field[47] = temp;
    field[52] = temp;
    field[53] = temp;
    field[56] = temp;
    field[57] = temp;
}

void FieldModel::setFighterIndex(int index)
{
    this->fighterIndex = index;
    this->fighterChoosed = true;
}



bool FieldModel::move(int tileIndex, int cellIndex)
{
    if (tileIndex == cellIndex) return false;
    if (tileIndex >= FIELD_SIZE || cellIndex >= FIELD_SIZE) return false;

    auto posTile = getxy(tileIndex);
    auto posCell = getxy(cellIndex);

    bool result = false;

    if (posTile.first == posCell.first){
        if (abs(posTile.second - posCell.second) == 1) result = true;
    }
    else{
        if (posTile.second == posCell.second){
            if (abs(posTile.first - posCell.first) == 1) result = true;
        }
    }
    Tile temp;

    if (result) {
        temp = field[cellIndex];
        field[cellIndex] = field[tileIndex];
        field[tileIndex] = temp;
    }
    emit dataChanged(createIndex(0, 0), createIndex(FIELD_SIZE, 0));
    return true;
}

std::pair<int, int> FieldModel::getxy(int index)
{
    int row = index / DIMENSION;
    int col = index % DIMENSION;

    return std::make_pair(row, col);
}

void FieldModel::setCell(int index)
{
    if (index >= FIELD_SIZE ) return;

    if (field[index].ismy){
        setFighterIndex(index);

        emit dataChanged(createIndex(0, 0), createIndex(FIELD_SIZE, 0));
        return;
    }

    if(field[index].isvoidTile){
        if(fighterChoosed){
            bool result = move(fighterIndex, index);
            if (result) {
                emit isMoved(fighterIndex, index, field[fighterIndex].role);
                emit dataChanged(createIndex(0, 0), createIndex(FIELD_SIZE, 0));
            }
        }
    }

}

void FieldModel::setTile(Tile tile, int index)
{
    if (index >= FIELD_SIZE) return;
    field[index] = tile;
    emit dataChanged(createIndex(0, 0), createIndex(FIELD_SIZE, 0));
}

size_t FieldModel::getFighterIndex() const
{
    return fighterIndex;
}

bool FieldModel::isChoosed(int index) const
{
    if (index >= FIELD_SIZE ) return false;
    return field[index].choosed;
}

Tile FieldModel::getTile(int index) const
{
    if (index >= FIELD_SIZE ) return {};
    return field[index];
}

QVariant FieldModel::getText(int index) const
{
    QVariant result;
    if (!field[index].isvoidTile) result = static_cast<int>(field[index].role);
    if (field[index].isalien) result = "S";
    if (field[index].isvoidTile && FIELD_SIZE == 40 ) result =  "?";

    return result;
}

std::vector<Tile> FieldModel::getmodelField()
{
    return field;
}
