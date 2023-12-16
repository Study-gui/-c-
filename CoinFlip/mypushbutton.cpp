#include "mypushbutton.h"
#include<QPainter>
#include<QPropertyAnimation>
#include<QDebug>
Mypushbutton::Mypushbutton(QString normalImg,QString pressedImg,QWidget *parent)
    : QPushButton{parent},mNormalImg(normalImg),mPressedImg(pressedImg)
{
    mstat=Normal;
}


void Mypushbutton::movedone()
{
  //1 位置大小属性发生变化
  //2 给定开始的位置大小属性
  //3 给定结束的位置大小属性·
  //4 给定速度，给定动画时长
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setDuration(100);//100毫秒
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

void Mypushbutton::moveup()
{
    QPropertyAnimation* animation=new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setDuration(100);//100毫秒
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Mypushbutton::paintEvent(QPaintEvent *e)
{
    //绘出按钮图片
    QPainter painter(this);
    QPixmap pix;
    if(mstat==Normal)
    pix.load(mNormalImg);
    if(mstat==Pressed)
    pix.load(mPressedImg);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //qDebug()<<this->text();
    painter.drawText(0,0,this->width(),this->height(),Qt::AlignHCenter|Qt::AlignVCenter,this->text());

}

void Mypushbutton::mousePressEvent(QMouseEvent *e)
{
    mstat=Pressed;
    //更新
    this->update();
    //发出信号
    QPushButton::mousePressEvent(e);
}

void Mypushbutton::mouseReleaseEvent(QMouseEvent *e)
{
    mstat=Normal;
    this->update();
    QPushButton::mouseReleaseEvent(e);
}

