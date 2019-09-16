#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controller.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    Controller controll(chess,not_read);


    engine.rootContext()->setContextProperty("controller_main", &controll);
    engine.rootContext()->setContextProperty("chessList",controll.get_QmlBoardList());


    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
