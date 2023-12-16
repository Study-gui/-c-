#include "startscene.h"
#include<Mypushbutton.h>
#include<QTimer>
#include<QSound>
StartScene::StartScene(QWidget *parent)
    : myMainWindow{parent}
{
    //设置开始场景
    this->setWindowTitle("开始场景");
    //创建按钮
    Mypushbutton* btn=new Mypushbutton(":/C:/Users/2814554384/Desktop/res/MenuSceneStartButton.png",":/C:/Users/2814554384/Desktop/res/MenuSceneStartButton.png",this);
    btn->resize(114,114);
    //按钮居中，位于垂直3/4的位置
    //x轴位于窗口宽度/2-按钮窗口宽度/2
    //y轴位于窗口宽度*3/4-按钮宽度的的/2
    btn->move((this->width()-btn->width())/2,(this->height()*3/4-btn->height()/2));

    //接受点击返回的信号，发生信号与槽，返回开始页面
    connect(&this->mselectscene,&selectscene::backBtnclick,[=](){
        //显示开始页面，关闭进入页面
        this->show();
        this->mselectscene.hide();
    });


    //按下按钮的型号与槽
    connect(btn,&Mypushbutton::clicked,[=](){
        //将按钮设置为不可用
        btn->setEnabled(false);

        btn->movedone();
        //往上走的动画，会覆盖往下走的动画
        //要等待动画播放完在播放下一个动画
        QTimer::singleShot(150,[=](){
            btn->moveup();
        });
        //将按钮设置为可用
        QTimer::singleShot(150,[=](){
            btn->setEnabled(true);
            //按下按钮后，隐藏开始页面，进入页面
            this->hide();

            this->mselectscene.show();
        });
    });


}
