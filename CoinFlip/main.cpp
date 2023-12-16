#include "mymainwindow.h"

#include <QApplication>
#include<startscene.h>
#include<selectscene.h>
#include<selectscene.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // myMainWindow w;
    // w.show();
    //创建开始窗口
    StartScene w;
    w.show();

    // selectscene w1;
    // w1.show();

    return a.exec();
}
