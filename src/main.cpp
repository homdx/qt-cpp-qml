#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "downloadmanager.h"
#include "backend.h"

int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));


    //QCoreApplication app(argc, argv);


    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
 qmlRegisterType<BackEnd>("io.qt.examples.backend", 1, 0, "BackEnd");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    QStringList arguments = app.arguments();
    arguments.takeFirst();      // remove the first argument, which is the program's name

//    if (arguments.isEmpty()) {
//        printf("Qt Download example\n"
//               "Usage: downloadmanager url1 [url2... urlN]\n"
//               "\n"
//               "Downloads the URLs passed in the command-line to the local directory\n"
//               "If the target file already exists, a .0, .1, .2, etc. is appended to\n"
//               "differentiate.\n");
//        return 0;
//    }

//    DownloadManager manager;
//    manager.append(arguments);

    engine.load(url);
    //engine.rootContext()->setContextProperty("myGlobalObject", myGlobal); // the object will be available in QML with name "myGlobalObject"
    return app.exec();
}
