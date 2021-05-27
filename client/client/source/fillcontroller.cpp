#include <fillcontroller.h>



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


//FieldModel* FillController::getmodel()
//{
//    return m_gmodelptr;
//}

//FightersModel* FillController::getFmodel()
//{
//    return m_fmodelptr;
//}

void FillController::fighterChoosed(int index)
{
    if (index >= m_fmodel.FIELD_SIZE) return;

    m_fmodel.setChoosedtileIndex(index);
    m_fmodel.dataChenged();
}

void FillController::tileChoosed(int index)
{
    int fighterIndex =m_fmodel.choosedtileIndex();
    if(fighterIndex == -1) return;
    Tile temp = m_fmodel.getTile(fighterIndex);
    m_gmodel.setTile(temp, index);
    m_fmodel.decreaseCount(fighterIndex);
}

void FillController::removeTile(int index)
{
    int role = m_gmodel.getTile(index).role;
    Tile voidTile = Tile(TileState::flag,
                         TileState::notvoidCell,
                         TileState::voidTile,
                         TileState::notMy,
                         TileState::alien);
    m_gmodel.setTile(voidTile, index);
    m_fmodel.increaseCount(role);
}

int FillController::choosedIndex()
{
    return m_fmodel.choosedtileIndex();
}

std::vector<Tile> FillController::getField()
{
    return FillController::m_gmodel.getmodelField();
}

bool FillController::isValidModel()
{
    bool result = true;
    for (int i = 0 ; i < m_fmodel.FIELD_SIZE; ++i){
        if (m_fmodel.getTile(i).count != 0) result = false;
    }
    return result;
}

