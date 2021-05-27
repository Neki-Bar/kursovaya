#ifndef APPDATA_H
#define APPDATA_H

#include <QString>


class AppData{
public:
    AppData();
    ~AppData();

    AppData& operator = (const AppData& data);
    AppData(AppData& data);
    bool isAutorisated() const;

    QByteArray username() const;

    QByteArray password() const;



private:
    bool m_isAutorisated;
    QByteArray m_username;
    QByteArray m_password;


};


#endif // APPDATA_H
