#ifndef CANVASWIDGET_H
#define CANVASWIDGET_H

#include <QWidget>
#include"defines.h"
#include"SystemInfo.h"

//namespace Ui {
//class ScreenCanvasWidget;
//}

class ScreenCanvasWidget : public QWidget
{
    Q_OBJECT

//private:
//    Ui::ScreenCanvasWidget *ui;


public:
//    explicit ScreenCanvasWidget(QWidget *parent = nullptr);
    ~ScreenCanvasWidget();

    //单例模式，对外开放的接口
    static ScreenCanvasWidget* getSingleCanvas();
    void initCanvas(); //初始化承托截图界面的Widget：最大化窗口、无边框等操作

private:
    ScreenCanvasWidget(); // 构造设为private，想定义为单例模式

    //单例模式
    //唯一的对象实例
    static ScreenCanvasWidget* m_singleCanvas;

public:

    SystemInfo* m_systemInfo;

    QPixmap* m_originPixmap;//桌面当前截图原图
    QPixmap* m_grayPixmap;//桌面当前截图的灰化图

    void get_originPixmap();//获取桌面的截图原图，就是初始化m_originPixmap
    void get_grayPixmap();//获取 桌面的截图原图 的 灰度图，就是初始化m_grayPixmap

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif





