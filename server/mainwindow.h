#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QMap>
#include <QTextStream>
#include <QtNetwork>
#include <QTcpSocket>
#include <QObject>
#include <QByteArray>
#include <QDebug>
#include "player.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void send_status(const char*);
signals:
    void all_connected();
    void all_ready();
private slots:
    void on_start_bt_clicked();
    void on_stop_bt_clicked();
    void newuser();
    void show_map(QString msg,int descr);
    void slotReadClient();
    void parse_msg(QString,int);
    size_t identify_player(int id);
    QVector<QVector<int>> convert_str_to_matrix(QString msg);
private:
    vector <Player *> pls;
    Ui::MainWindow *ui;
    QTcpServer * listener;
    QMap<int,QTcpSocket*> SClients;
    bool server_status;
    bool game_started;

};

#endif // MAINWINDOW_H
