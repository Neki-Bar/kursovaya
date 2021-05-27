#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCoreApplication>

#include "appcontroller.h"
#include <fillcontroller.h>

int main(int argc, char *argv[])
{

    #if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

        QGuiApplication app(argc, argv);

        qmlRegisterType<AppController> ("CustControll", 1, 0, "AppController");
        qmlRegisterType<FillController> ("CustControll", 1, 0, "FillController");

        QQmlApplicationEngine engine;
        const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
        QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                         &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
        engine.load(url);


        return app.exec();

}
