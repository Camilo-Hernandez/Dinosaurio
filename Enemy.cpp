#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include <QDebug>
#include <iostream>

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPos(800,144);

    // drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Enemy::move(){
    // Chque entre el cactus y el dinosaurio si las coordenadas coinciden.
    if((this->x()==game->player->x())&&(this->y()==game->player->y()+10)){
        qDebug()<<"Colisión";
    }
    //Usando "flancos de subida" para calcular el choque y los HP restantes.
    lecturaanterior=lecturaactual;
    choque=this->collidesWithItem(game->player);
    lecturaactual=choque;
    if((lecturaactual==true)&&(lecturaanterior==false)){
        qDebug() << "Chocaste";
        game->health->decrease();
    }
    // end game
    if(game->health->getHealth()==0){
        qDebug() << "Perdiste";}
    // move enemy left
    setPos(x()-5,y());
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}
