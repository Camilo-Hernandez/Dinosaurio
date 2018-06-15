#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
    bool choque=false;
    bool lecturaanterior;
    bool lecturaactual=false;
public slots:
    void move();
};

#endif // ENEMY_H
