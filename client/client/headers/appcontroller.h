#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <appdata.h>
#include <fieldmodel.h>
//#include <fillcontroller.h>



class AppController : public QObject
{
    Q_OBJECT
public:
    virtual ~AppController() {}
//    Q_INVOKABLE static AppData *app();
//    Q_INVOKABLE static FieldModel *model();
    Q_INVOKABLE bool isAutorisated();
    Q_INVOKABLE void setCell(int index);
    Q_INVOKABLE bool isChoosed(int index) const;
    Q_INVOKABLE void moveModel();

    bool isAutorisated() const;
    QByteArray username() const;
    QByteArray password() const;






public slots:
    //    void toCall();
//    void toText();
//    void toExit();
//    void toStatistic();
//    void toSignUp();
//    void toLogIn();
    bool logIn(QString& username, QString& password);
    bool signUp(QString& username, QString& password, QString& confirm);

private:

    static AppData m_app;
    static FieldModel m_model;

    static AppData* m_appptr;
    static FieldModel* m_modelptr;


};


AppData AppController::m_app = AppData();
FieldModel AppController::m_model = FieldModel(100, 10);

AppData* AppController::m_appptr = &m_app;
FieldModel* AppController::m_modelptr = &m_model;
#endif //APPCONTROLLER_H
