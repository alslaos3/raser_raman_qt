#include "mainwindow.h"
#include <unistd.h>
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QDebug>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap;
    pixmap.load(":logo.png");
    QPixmap new_pixmap = pixmap.scaledToWidth(1000);
    QTimer timer;
    QSplashScreen splash(new_pixmap);
    splash.show();

    for (int i = 0; i < 100; i++) {
        QString message = QString("Loading %1%").arg(i+1);
        splash.showMessage(message, Qt::AlignBottom|Qt::AlignCenter, Qt::black);
        QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit);
        loop.exec();
    }
    splash.close();

//    sleep(5);
//    splash.close();

    MainWindow w;
    w.show();

    return a.exec();
}
