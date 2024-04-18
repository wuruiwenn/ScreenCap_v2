#include "screencanvaswidget.h"
#include "ui_screencanvaswidget.h"


//ScreenCanvasWidget::ScreenCanvasWidget(QWidget *parent) :
//    QWidget(parent),
//    ui(new Ui::ScreenCanvasWidget)
//{
//    ui->setupUi(this);
//}

ScreenCanvasWidget::~ScreenCanvasWidget()
{
//    delete ui;
    qDebug() << "ScreenCanvasWidget析构\n";
    delete m_singleCanvas;
    delete m_grayPixmap;
    delete m_originPixmap;
}

ScreenCanvasWidget::ScreenCanvasWidget()
{
    initCanvas();//初始化承托截图的背景画布，

    systemInfo = new SystemInfo();

    get_originPixmap();//获取桌面截图原图
    get_grayPixmap();//获取桌面截图原图 的 灰度图
}

void ScreenCanvasWidget::get_originPixmap(){
    m_originPixmap = systemInfo->getDesktopScreen();
}
void ScreenCanvasWidget::get_grayPixmap(){
    //获取屏幕截图的灰度图，本质就是在原图基础上继续绘制灰色
    m_grayPixmap = systemInfo->getDesktopGrayScreen();
}

void ScreenCanvasWidget::initCanvas()
{
    //初始化一些指针：
    m_originPixmap = nullptr;
    m_grayPixmap = nullptr;

    //全屏化，无标题化，阴影化 ...
    this->resize(1900,1200);
    this->setWindowTitle("ScreenCanvas");


    // 窗口置顶 + 隐藏标题栏
//    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    //设置承托截图的背景画布所在窗口的大小，一般是全屏
//    this->setFixedSize(QGuiApplication::primaryScreen()->size());
    this->setFixedSize(1200,800);//暂时先设置这
    this->setWindowFlag(Qt::WindowStaysOnTopHint);//置顶
//    this->resize(QGuiApplication::primaryScreen()->size());
    this->setWindowIcon(QIcon(":/reso/imgs/logo.svg"));
}


//单例模式，初始化
//懒汉式
ScreenCanvasWidget* ScreenCanvasWidget::m_singleCanvas = nullptr;
ScreenCanvasWidget* ScreenCanvasWidget::getSingleCanvas()
{
    if(m_singleCanvas == nullptr)
    {
        m_singleCanvas = new ScreenCanvasWidget();
    }
    return m_singleCanvas;
}









