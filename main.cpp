#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/splash.png"));
    splash->show();
    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;
    splash->showMessage(QObject::tr("Setting up the main window..."), topRight , Qt::black);
    //MainWindow mainWin;
    //splash->showMessage(QObject::tr("Loading modules..."),topRight, Qt::white);
    //loadModules();
    //splash->showMessage(QObject::tr("Establishing connections..."),topRight, Qt::white);
    //establishConnections();

    MainWindow w;
QTimer::singleShot(4000,splash,SLOT(close()));
QTimer::singleShot(2000,&w,SLOT(show()));
    //w.show();

    //splash->finish(&mainWin);
    //delete splash;

    return a.exec();
}
