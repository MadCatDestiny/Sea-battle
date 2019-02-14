#include "player.h"

Player::Player(QTcpSocket *socket)
{
    this->sock = socket;
    this->ready = false;
    this->ships_count = 10;
    this->map = QVector<QVector<int>>(10,QVector<int>(10,0));
}

bool Player::check_point(QPoint p)
{
    if (this->map[p.x()][p.y()] == 0){
        this->map[p.x()][p.y()] = -2; // мимо
        return false;
    }
    else {
        this->map[p.x()][p.y()] = -1; //в цель
        return true;
    }
}

void Player::set_ready(bool isReady)
{
    this->ready = isReady;
}

void Player::set_map(QVector<QVector<int>> new_map)
{
    this->map = new_map;
}

void Player::show_map()
{
    for (auto v : map)
    {
        for (auto d : v)
            cout << d << " ";
        cout << endl;
    }
}

bool Player::isFirst() const
{
    return first_step;
}

bool Player::isReady() const
{
    return ready;
}

bool Player::isEmpty() const
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (map[i][j] > 0)
                return false;

    return true;
}

int Player::descriptor() const
{
    return sock->socketDescriptor();
}

QTcpSocket *Player::socket()
{
    return sock;
}

void Player::set_first_step(bool isFirst)
{
    this->first_step = isFirst;
}
