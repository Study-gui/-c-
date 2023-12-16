#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include <QMainWindow>
#include"mymainwindow.h"
class selectscene : public myMainWindow
{
    Q_OBJECT
public:
    explicit selectscene(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
signals:
    //点击返回窗口，形成的槽
    void backBtnclick();
};

#endif // SELECTSCENE_H
