#include "appcontroller.h"
#include "appdata.h"
#include <fieldmodel.h>
#include <QDebug>
#include <QCryptographicHash>



bool AppController::logIn(QString &username, QString &password)
{
    if (username.length() == 0 || password.length() == 0) return false;

//    валидация логина и пароля

    QByteArray Uusername = username.toUtf8();
    QByteArray Upassword = password.toUtf8();

    QCryptographicHash usernameHash(QCryptographicHash::Blake2s_256);
    QCryptographicHash passwordHash(QCryptographicHash::Blake2s_256);

    usernameHash.addData(Uusername);
    passwordHash.addData(Upassword);


//    отправка  на сервер;
//    получение ответа;


//    если есть такой пользователь то запись в AppData, если нет то return false

    qInfo() << "log In pressed" << username << password;
    return false;
}

bool AppController::signUp(QString &username, QString &password, QString &confirm)
{
    if (password != confirm){
        return false;
    }
    if (username.length() == 0 || password.length() == 0) return false;
    //    валидация логина и пароля

    QByteArray Uusername = username.toUtf8();
    QByteArray Upassword = password.toUtf8();

    QCryptographicHash usernameHash(QCryptographicHash::Blake2s_256);
    QCryptographicHash passwordHash(QCryptographicHash::Blake2s_256);

    usernameHash.addData(Uusername);
    passwordHash.addData(Upassword);

//    отправка  на сервер;
//    получение ответа;

//    если уже есть return false, иначе запись в AppData

    qInfo() << "sign Up pressed" << username << password << confirm;
    return true;
}



bool AppController::isAutorisated()
{
    return m_app.isAutorisated();
}

void AppController::setCell(int index)
{
    m_model.setCell(index);
}

bool AppController::isChoosed(int index) const
{
    return m_model.isChoosed(index);
}


//FieldModel* AppController::model()
//{
//    return m_modelptr;
//}



//AppData *AppController::app()
//{
//    return m_appptr;
//}


QByteArray AppController::username() const
{
    return m_app.username();
}


void AppController::moveModel()
{
//    std::vector<Tile> field = FillController::getField();
    for (int i = 0 ; i < m_model.FIELD_SIZE; ++i){
//        m_model.setTile(field[i], i);
    }
}

