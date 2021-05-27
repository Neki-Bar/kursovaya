#ifndef FIELDMODEL_H
#define FIELDMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <tile.h>


class FieldModel : public QAbstractListModel
{
    Q_OBJECT
public:
    const size_t DIMENSION;
    const size_t FIELD_SIZE;
    FieldModel(int size, int dim);

    FieldModel& operator =(FieldModel& model);
    FieldModel(FieldModel& model);
    int rowCount(const QModelIndex & parent = QModelIndex ()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setVoidCell(std::vector<Tile>& field);

    void setFighterIndex(int index);
    void setCellIndex(int index);





    bool move(int tileIndex, int cellIndex);
    std::pair<int, int> getxy(int index);

    void setCell(int index);
    void setTile(Tile tile, int index);



    size_t getFighterIndex() const;
    bool isChoosed(int index) const;
    Tile getTile(int index) const;
    QVariant getText(int index) const;
    std::vector<Tile> getmodelField();



signals:
    void isMoved(int firstIndex, int secondIndex, Tile::fighterType rang);


private:

    std::vector<Tile> field;

    bool fighterChoosed;
    size_t fighterIndex;

    enum fieldModelRoles{
        RangRole = Qt::UserRole + 1,
        VoidCellRole,
        VoidTileRole,
        IsMyRole,
        IsAlienRole
    };


};

#endif // FIELDMODEL_H
