#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include<mymainwindow.h>
#include<coinpushbutton.h>
class playscene : public myMainWindow
{
    Q_OBJECT
public:
  playscene(int level,QWidget *parent = nullptr);
protected:
    void filp(int row,int col);
    //判断是否胜利
    void judgewin();
    void paintEvent(QPaintEvent *event);
private:
    //创建判断胜利的
    bool mHaswin;
    //创建一个二维的矩阵按钮
    Coinpushbutton* coin[4][4];
signals:
    void backBtnclick();
};

#endif // PLAYSCENE_H
