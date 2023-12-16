#ifndef COINPUSHBUTTON_H
#define COINPUSHBUTTON_H
#include<QPushButton>
#include <QWidget>
#include<QTimer>
class Coinpushbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit Coinpushbutton(QWidget *parent = nullptr);
    int getMstat() const;
    void setMstat(int newMstat);
    //翻转函数
    void filp();
    //控制帧数翻转
    void setMstatanimation(int stat);
protected:
    void paintEvent(QPaintEvent *e);
private:
    //金币状态
    int mstat;
    //帧数
    int frame;
    //定时器
    QTimer mtimer;
    Q_PROPERTY(int mstat READ getMstat WRITE setMstat NOTIFY mstatChanged FINAL)

signals:
    void mstatChanged();
};

#endif // COINPUSHBUTTON_H
