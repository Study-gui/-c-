#include "mymainwindow.h"
#include "ui_mymainwindow.h"
#include<QPainter>
myMainWindow::myMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myMainWindow)
{
    ui->setupUi(this);
    //设置窗口标题
    this->setWindowTitle("翻金币");
    //设置窗口的Icon
    this->setWindowIcon(QIcon(":/C:/Users/2814554384/Desktop/res/Coin0001.png"));
    //设置窗口的固定大小
    this->setFixedSize(320,588);
}

myMainWindow::~myMainWindow()
{
    delete ui;

}

void myMainWindow::on_actionquit_triggered()
{
    this->close();
}

void myMainWindow::paintEvent(QPaintEvent *event)
{
    //用绘图事件来画出背景
    QPainter painter(this);
    QPixmap pix(":/C:/Users/2814554384/Desktop/res/MenuSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

