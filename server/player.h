#ifndef PLAYER_H
#define PLAYER_H

#include <QTcpSocket>
#include <QTcpServer>
#include <QVector>
#include <iostream>
#include <QPoint>
#include <QThread>
using namespace std;

class Player
{
private:
    bool ready;
    bool first_step;
    QTcpSocket * sock;
    QVector <QVector<int>> map;
    size_t ships_count;
public:
    Player(QTcpSocket * socket);
    bool check_point(QPoint p);
    void set_ready(bool isReady);
    void set_map(QVector <QVector<int>> new_map);
    void set_first_step(bool isFirst);
    void show_map();
    bool isFirst()const;
    bool isReady()const;
    bool isEmpty()const;
    int descriptor()const;
    QTcpSocket * socket();
};

#endif // PLAYER_H
