#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy2.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/dinosaur.png"));
    QTimer * move_timer = new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this,SLOT(jump()));
    move_timer->start(50);
}

void Player::keyPressEvent(QKeyEvent *event){
    // make the dinosaur to jump
    desp=10;
    if ((event->key() == Qt::Key_Up)||(event->key() == Qt::Key_Space)){
        subida = true;
    }
    // make the dinosaur to agacharse
    else if (event->key() == Qt::Key_Down){
        setPixmap(QPixmap(":/images/duck.png"));
        setPos(100,156);
    }
}

void Player::keyReleaseEvent(QKeyEvent *liberarDown){
    if (liberarDown->key() == Qt::Key_Down){
        setPixmap(QPixmap(":/images/dinosaur.png"));
        setPos(100,132);
    }
}


void Player::jump(){
    if(subida){
        this->setY(y()-desp);
        count++;
    }
    if (count == 11){
        subida = false;
        bajada=true;
    }
    if (bajada){
        this->setY(y()+desp);
        count++;
        if(count==22)bajada=false;
    }
    if(!bajada && !subida)count=0;
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::spawn2()
{
    Enemy2 * enemy2 = new Enemy2();
    scene()->addItem(enemy2);
}


