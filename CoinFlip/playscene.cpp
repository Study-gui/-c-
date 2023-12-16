#include "playscene.h"
#include<mypushbutton.h>
#include<QPainter>
#include<QPixmap>
#include<QMenuBar>
#include<QLabel>
#include<coinpushbutton.h>
#include<dataconfig.h>
#include<QMessageBox>
#include<QPropertyAnimation>
playscene::playscene(int level,QWidget *parent)
    : myMainWindow{parent}
{
    this->mHaswin=false;
    Mypushbutton* btnback=new Mypushbutton(":/C:/Users/2814554384/Desktop/res/BackButton.png",":/C:/Users/2814554384/Desktop/res/BackButtonSelected.png",this);
    //调整back按钮的位置
    btnback->move(this->width()-btnback->width(),this->height()-btnback->height());
    connect(btnback,&QPushButton::clicked,[=](){
        this->backBtnclick();
    });
    //添加左下角的label
    QLabel* label=new QLabel(this);
    label->setText(QString("Level:%1").arg(level));
    label->resize(150,50);
    //设置字体
    label->setFont(QFont("华文新魏",20));
    label->move(30,this->height()-label->height());
    //创建硬币按钮
    int colwidth=50;
    int rowheight=50;
    int xoffset=57;
    int yoffset=200;

    //导入关卡数据
    dataConfig data;
    QVector<QVector<int>> dataArray=data.mData[level];

    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            //x坐标=列数*行间隔+x整体偏移
            //y坐标=行数*列间隔+y整体偏移
            int x=colwidth*col+xoffset;
            int y=rowheight* row+yoffset;
            Coinpushbutton* btn=new Coinpushbutton(this);
            btn->resize(50,50);
            btn->move(x,y);
            //把按钮存入按钮数组中
            coin[row][col]=btn;
            //将二维数组的信息进行导入
            btn->setMstat(dataArray[row][col]);
            //点击按钮取反
            connect(btn,&Coinpushbutton::clicked,[=](){
                //让周围进行翻动
                //btn->filp();
                this->filp(row,col);
            });
        }
    }


}

void playscene::filp(int row, int col)
{
    //判断是否已经胜利
    if(this->mHaswin)
    {
        return ;
    }
    //点击就翻转
    this->coin[row][col]->filp();
    //中间先翻转，四周在开始翻转
    QTimer::singleShot(240,[=](){
        //下一行的按钮进行翻转
        if(row+1<4)
        {
            this->coin[row+1][col]->filp();
        }
        //上一行的按钮进行翻转
        if(row-1>=0)
        {
            this->coin[row-1][col]->filp();
        }
        //左边的按钮进行翻转
        if(col-1>=0)
        {
            this->coin[row][col-1]->filp();
        }
        //右边的按钮进行翻转
        if(col+1<4)
        {
            this->coin[row][col+1]->filp();
        }
         this->judgewin();
    });


}

void playscene::judgewin()
{
    //判断是否胜利
    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            //是银币就退出
            if(!this->coin[row][col]->getMstat())
            {
                return ;
            }
        }
    }
    //没有退出，就说明是金币
    //QMessageBox::information(this,"恭喜","你获得胜利");
    //胜利变量置为胜利
    this->mHaswin=true;
    QLabel* labelwin=new QLabel(this);
    QPixmap pix(":/C:/Users/2814554384/Desktop/res/LevelCompletedDialogBg.png");
    labelwin->setPixmap(pix);
    labelwin->resize(pix.size());
    labelwin->show();
    //调到居中,隐藏起来
    labelwin->move((this->width()-labelwin->width())/2,-labelwin->height());
    //设置动画播放
    QPropertyAnimation* animation=new QPropertyAnimation(labelwin,"geometry",this);
    //开始，结束，和时长
    animation->setStartValue(labelwin->geometry());
    animation->setEndValue(QRect(labelwin->x(),labelwin->y()+120,labelwin->width(),labelwin->height()));
    animation->setDuration(1000);
    //设置动画的运动曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    //动画播放完自动删除对象
    animation->start(QAbstractAnimation::DeleteWhenStopped);

}

void playscene::paintEvent(QPaintEvent *event)
{
    //创建画家
    QPainter painter(this);
    //把画家进行整体偏移
    painter.translate(0,this->menuBar()->height());
    QPixmap pix(":/C:/Users/2814554384/Desktop/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //追加图片资源
    pix.load(":/C:/Users/2814554384/Desktop/res/Title.png");
    pix=pix.scaled(pix.width()/2,pix.height()/2);
    painter.drawPixmap(0,0,pix);
}
