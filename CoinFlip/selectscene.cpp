#include "selectscene.h"
#include<QPushButton>
#include<QPainter>
#include<QPixmap>
#include<QMenuBar>
#include<mypushbutton.h>
#include<playscene.h>
selectscene::selectscene(QWidget *parent)
    : myMainWindow{parent}
{
    Mypushbutton* btnback=new Mypushbutton(":/C:/Users/2814554384/Desktop/res/BackButton.png",":/C:/Users/2814554384/Desktop/res/BackButtonSelected.png",this);
    //调整back按钮的位置
    btnback->move(this->width()-btnback->width(),this->height()-btnback->height());
    connect(btnback,&QPushButton::clicked,[=](){
        this->backBtnclick();
    });
    //按钮固定间隔,列宽间隔
    const int colwidth=70;
    //行高
    const int rowheight=70;
    //整体偏移
    const int xoffset=25;
    const int yoffset=130;
    //画出20个按钮
    for(int i=0;i<20;i++)
    {

        //QPushButton* btn=new QPushButton(QString::number(i+1),this);
        Mypushbutton* btn=new Mypushbutton(":/C:/Users/2814554384/Desktop/res/LevelIcon.png",":/C:/Users/2814554384/Desktop/res/LevelIcon.png",this);
        btn->setText(QString::number(i+1));
        //排列
        //行 i/4
        //列 i%4
        int row=i/4;
        int col=i%4;
        //x坐标=列数*行间隔+x整体偏移
        //y坐标=行数*列间隔+y整体偏移
        int x=colwidth*col+xoffset;
        int y=rowheight* row+yoffset;
        btn->resize(57,57);
        btn->move(x,y);
        //跳到第三个场景
        connect(btn,&Mypushbutton::clicked,[=](){
            //一直new会形成内存泄漏，所以要进行关闭释放
            playscene* play=new playscene(i+1);
            play->setAttribute(Qt::WA_DeleteOnClose);
            this->hide();
            play->show();


            connect(play,&playscene::backBtnclick,[=](){
                this->show();
                play->close();
            });

        });
    }

}

void selectscene::paintEvent(QPaintEvent *event)
{
    //创建画家
    QPainter painter(this);
    //把画家进行整体偏移
    painter.translate(0,this->menuBar()->height());
    QPixmap pix(":/C:/Users/2814554384/Desktop/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //追加图片资源
    pix.load(":/C:/Users/2814554384/Desktop/res/Title.png");
    painter.drawPixmap(0,0,pix);
}
