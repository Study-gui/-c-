#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class myMainWindow;
}
QT_END_NAMESPACE

class myMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    myMainWindow(QWidget *parent = nullptr);
    ~myMainWindow();

private slots:
    void on_actionquit_triggered();
protected:
    void paintEvent(QPaintEvent *event);
private:
    Ui::myMainWindow *ui;
};
#endif // MYMAINWINDOW_H
