#ifndef FILLCONTROLLER_H
#define FILLCONTROLLER_H

#include <QObject>
#include <fieldmodel.h>
#include <fightersmodel.h>



class FillController : public QObject
{
    Q_OBJECT
public:
    FillController();
    virtual ~FillController() {}
//    Q_INVOKABLE static FieldModel *getmodel();
//    Q_INVOKABLE static FightersModel *getFmodel();
    Q_INVOKABLE void fighterChoosed(int index);
    Q_INVOKABLE void tileChoosed(int index);
    Q_INVOKABLE void removeTile(int index);
    Q_INVOKABLE int choosedIndex();
    Q_INVOKABLE bool isValidModel();

    static std::vector<Tile> getField();

private:
    static FieldModel m_gmodel;
    static FightersModel m_fmodel;

    static FieldModel* m_gmodelptr;
    static FightersModel* m_fmodelptr;
};


FieldModel FillController::m_gmodel = FieldModel(40, 10);
FightersModel FillController::m_fmodel = FightersModel();

FieldModel* FillController::m_gmodelptr = &m_gmodel;
FightersModel* FillController::m_fmodelptr = &m_fmodel;
#endif //FILLCONTROLLER_H
