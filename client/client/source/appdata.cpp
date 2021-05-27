#include "appdata.h"
#include <QSettings>
#include<QCoreApplication>

AppData::AppData() {
    QSettings settings("MySoft", "Stratego");
    m_isAutorisated = settings.value("status").value<bool>();
    m_username = settings.value("username").value<QByteArray>();
    m_password = settings.value("password").value<QByteArray>();
}

AppData::~AppData()
{
    QCoreApplication::setOrganizationName("MySoft");
    QCoreApplication::setApplicationName("Stratego");
    QSettings settings;

    settings.setValue("status", m_isAutorisated);
    settings.setValue("username", m_username);
    settings.setValue("password", m_password);

}

AppData &AppData::operator =(const AppData &data)
{
    this->m_isAutorisated = data.m_isAutorisated;
    this->m_password = data.m_password;
    this->m_username = data.m_username;

    return *this;
}

AppData::AppData(AppData &data)
{
    this->m_isAutorisated = data.m_isAutorisated;
    this->m_password = data.m_password;
    this->m_username = data.m_username;
}

bool AppData::isAutorisated() const
{
    return m_isAutorisated;
}

QByteArray AppData::username() const
{
    return m_username;
}

QByteArray AppData::password() const
{
    return m_password;
}


