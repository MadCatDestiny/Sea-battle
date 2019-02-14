#include "mainwindow.h"
#include <QApplication>
#include "player.h"
#include <QTcpSocket>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /*QTcpSocket * s = new QTcpSocket();
    Player p (s);
    p.show_map();*/

    return a.exec();
}
