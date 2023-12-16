#ifndef STARTSCENE_H
#define STARTSCENE_H
#include"mymainwindow.h"
#include <QMainWindow>
#include<selectscene.h>
class StartScene : public myMainWindow
{
    Q_OBJECT
public:
    explicit StartScene(QWidget *parent = nullptr);
    //创建进入页面窗口
    selectscene mselectscene;

signals:
};

#endif // STARTSCENE_H
