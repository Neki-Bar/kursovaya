
#include <fightersmodel.h>



FightersModel::FightersModel()
{
    row = std::vector<Tile>(FIELD_SIZE);
    std::vector<int> amount = {1, 1, 8, 5, 4, 4, 4, 3, 2, 1, 1, 6};
    for (int i = 0; i < FIELD_SIZE; ++i){
        row[i] = Tile(i, amount[i]);
    }
}

int FightersModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return FIELD_SIZE;
}

QVariant FightersModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return {};
    int listIndex = index.row();
    if (role == RangRole) return QVariant(static_cast<int>(row[listIndex].role));
    if (role == CountRole) return QVariant(row[listIndex].count);
    if (role == ColorRole) return QVariant(getColor(listIndex));
    return {};
}

QHash<int, QByteArray> FightersModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[RangRole] = "rang";
    roles[CountRole] = "amount";
    roles[ColorRole] = "color";
    return roles;
}

Tile FightersModel::getTile(int index)
{
    if (index >= FIELD_SIZE) return {};
    return row[index];
}

void FightersModel::increaseCount(int index)
{
    if (index >= FIELD_SIZE) return ;
    row[index].count++;
    emit dataChanged(createIndex(0, 0), createIndex(FIELD_SIZE, 0));
}

void FightersModel::decreaseCount(int index)
{
    if (index >= FIELD_SIZE) return ;
    row[index].count--;
    emit dataChanged(createIndex(0, 0), createIndex(FIELD_SIZE, 0));
}

QString FightersModel::getColor(int index) const
{
    if (index >= FIELD_SIZE) return {};
    if (index == m_choosedtileIndex) return "#000000";
    else return "#968F8D";
}

void FightersModel::dataChenged()
{
    emit dataChanged(createIndex(0, 0), createIndex(FIELD_SIZE, 0));
}

void FightersModel::Clear()
{
    row.clear();
}

int FightersModel::choosedtileIndex() const
{
    if (row[m_choosedtileIndex].count == 0) return -1;
    return m_choosedtileIndex;
}

void FightersModel::setChoosedtileIndex(int choosedtile)
{
    if (choosedtile >= FIELD_SIZE) return ;
    m_choosedtileIndex = choosedtile;
}


