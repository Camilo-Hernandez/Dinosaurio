#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Game.h"
#include <QDebug>
#include <iostream>
#include "Enemy2.h"

extern Game * game;

Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPos(700,110);

    // drew the rect
    setPixmap(QPixmap(":/images/bird.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(15);
}

void Enemy2::move(){
    // Chque entre el cactus y el dinosaurio si las coordenadas coinciden.
    if((this->x()==game->player->x())&&(this->y()==game->player->y()+10)){
        qDebug()<<"Colisión";
    }
    //Usando "flancos de subida" para calcular los HP restantes.
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
        //game->timer->stop();
    // move enemy left
    setPos(x()-5,y());
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy2::spawn()
{
    Enemy2 * enemy2 = new Enemy2();
    scene()->addItem(enemy2);
}
