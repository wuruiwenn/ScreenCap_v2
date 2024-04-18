#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include"defines.h"

#include"trayiconwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

private:
    Ui::MainWidget *ui;


public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();



// UI组件
private:
    QPushButton* toCapTrayBtn;//托盘方式，点击托盘再打开截图
    QPushButton* toCapBtn;//直接打开截图
    QPushButton* lineBtn;
    QSpacerItem* spacerLeft;//用于布局的弹簧
    QSpacerItem* spacerMid;
    QSpacerItem* spacerRight;

    QWidget* topWidget;//主界面上方的小widget

//界面相关
private:
    void initMainUI();//主界面初始化，包括按钮显示位置等

//系统托盘widget类
private:
    TrayiconWidget* trayWidget;


//槽函数
private slots:
    void toCapTrayBtnClickedHandler();



public:
    void resizeEvent(QResizeEvent *event) override;

};
#endif
