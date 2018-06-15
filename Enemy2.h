#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy2: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem * parent=0);
    bool choque=false;
    bool lecturaanterior;
    bool lecturaactual=false;
public slots:
    void move();
    void spawn();
};

#endif // ENEMY2_H
