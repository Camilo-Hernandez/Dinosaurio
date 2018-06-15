#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * liberarDown);
    int desp;
    int count=0;
    bool subida=false;
    bool bajada=false;
public slots:
    void spawn();
    void spawn2();
    void jump();
};

#endif // PLAYER_H
