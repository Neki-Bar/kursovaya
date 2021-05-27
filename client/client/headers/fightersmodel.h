#ifndef FIGHTERSMODEL_H
#define FIGHTERSMODEL_H

#include <QAbstractListModel>
#include <vector>
#include <tile.h>
#include <QString>

class FightersModel : public QAbstractListModel
{
    Q_OBJECT
public:
    static constexpr const size_t FIELD_SIZE {12};
    FightersModel();

    int rowCount(const QModelIndex & parent = QModelIndex ()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;



    int choosedtileIndex() const;
    void setChoosedtileIndex(int choosedtile);
    Tile getTile(int index);
    void increaseCount(int index);
    void decreaseCount(int index);
    QString getColor(int index) const;

    void dataChenged();

    void Clear();

private:
    int m_choosedtileIndex = 0;
    std::vector<Tile> row;

    enum fieldModelRoles{
        RangRole = Qt::UserRole + 1,
        CountRole,
        ColorRole
    };


};

#endif // FIGHTERSMODEL_H
