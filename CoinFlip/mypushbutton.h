#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H
#include<QPushButton>
#include <QWidget>
#include<QString>
class Mypushbutton : public QPushButton
{
    Q_OBJECT
public:
    Mypushbutton(QString normalImg,QString pressedImg, QWidget *parent = nullptr);
    enum Mypushbuttonstart
    {
        Normal,
        Pressed
    };

    //向下的动画
    void movedone();
    //向上的动画
    void moveup();
protected:
    void paintEvent(QPaintEvent *e);
    //进入鼠标点击和离开事件
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    //按钮图片和按下图片的路径
    QString mNormalImg;
    QString mPressedImg;
    Mypushbuttonstart mstat;
signals:
};

#endif // MYPUSHBUTTON_H
