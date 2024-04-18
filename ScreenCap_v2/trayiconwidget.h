#ifndef TRAYICONWIDGET_H
#define TRAYICONWIDGET_H

#include <QWidget>

#include"defines.h"
#include"screencanvaswidget.h"

namespace Ui {
class TrayiconWidget;
}

//系统托盘类：这个类封装系统托盘相关的东西，
//系统托盘类：包括托盘的激活选项菜单、系统托盘本身、内部承托屏幕截图的背景画布类实例
//为什么要把承托截图的背景画布类作为一个 系统托盘类的 属性？
//因为这个承载截图的全屏背景画布需要通过点击系统托盘来显示

class TrayiconWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrayiconWidget(QWidget *parent = nullptr);
    ~TrayiconWidget();

private:
    Ui::TrayiconWidget *ui;

//    系统托盘类的必要属性：
//    1、系统托盘
//    2、系统托盘所需的menu等
//    3、承托截图的背景画布Widget，点击托盘显示，即开始截图
private:
    QSystemTrayIcon* tray;//系统托盘
    QMenu* trayMenu;//菜单
    QAction* exitAct;//退出选项，用于菜单
    QAction* aboutAct;//关于选项，用于菜单
    void showMenu();//显示Menu

    ScreenCanvasWidget* screenCanvas;//承托截图的背景画布类
    void initTray();//设置托盘本身属性：图标等。初始化画布screenCanvas为nullptr

    void showScreenCanvas();


private slots:
    void trayActivatedHandler(QSystemTrayIcon::ActivationReason reason);
};



#endif
