#include "coinpushbutton.h"
#include<QPainter>
Coinpushbutton::Coinpushbutton(QWidget *parent)
    : QPushButton{parent}
{
    this->setMstat(1);
    //去边框
    this->setStyleSheet("QPushButton{border:Opx;}");
    //设置定时器的信号与槽
    connect(&this->mtimer,&QTimer::timeout,[=](){

        if(this->mstat==1)
        {
            this->frame--;
        }
        else{
            this->frame++;
        }
        //进行相应的帧数对应相应的图片
        QString newframe=QString(":/C:/Users/2814554384/Desktop/res/Coin000%1.png").arg(frame);
        this->setIcon(QIcon(newframe));
        //停止定时器
        if(this->frame==8||this->frame==1)
        {
            this->mtimer.stop();
        }

    });
}

int Coinpushbutton::getMstat() const
{
    return this->mstat;
}

void Coinpushbutton::setMstat(int newMstat)
{
    this->mstat=newMstat;
    if(this->mstat)
    {
        //表示为金币
        this->setIcon(QIcon(":/C:/Users/2814554384/Desktop/res/Coin0001.png"));
    }
    else
    {
        //表示为银币
        this->setIcon(QIcon(":/C:/Users/2814554384/Desktop/res/Coin0008.png"));
    }
    this->setIconSize(this->size());
}

void Coinpushbutton::filp()
{
   //直接取反
    this->setMstatanimation(!getMstat());
}

void Coinpushbutton::setMstatanimation(int stat)
{
    this->mstat=stat;
    if(this->mstat)
    {
        //0->1表示银币翻金币
        this->frame=8;
    }
    else{
        //1->0表示金币翻银币
        this->frame=1;
    }
    //设置每帧时长为30毫秒
    this->mtimer.start(30);
}

void Coinpushbutton::paintEvent(QPaintEvent *e)
{
    //绘出按钮图片
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/C:/Users/2814554384/Desktop/res/BoardNode(1).png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //调用父类的paintEvent
    QPushButton::paintEvent(e);
}
