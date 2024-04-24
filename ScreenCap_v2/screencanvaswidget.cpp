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
//    delete m_singleCanvas;//这会导致当前这句不断被执行，不会往下一行执行，最后程序异常终止
//    【这个我没找到原因，为什么会这样，可能是QT内部的机制】
//    不过，delete单例模式的指针，本来就不合理，
//    因为单例模式的指针一般是static
//    static意味着他的生命周期和整个程序一样，那么程序结束，该单例指针也会被销毁
//    qDebug() << "\n.........DELETE..........\n";
    delete m_grayPixmap;
    delete m_originPixmap;
    delete m_systemInfo;
}

ScreenCanvasWidget::ScreenCanvasWidget()
{
    initCanvas();//初始化承托截图的背景画布，

    m_systemInfo = new SystemInfo();

    get_originPixmap();//获取桌面截图原图
    get_grayPixmap();//获取桌面截图原图 的 灰度图
}

void ScreenCanvasWidget::get_originPixmap(){
    m_originPixmap = m_systemInfo->getDesktopScreen();
}
void ScreenCanvasWidget::get_grayPixmap(){
    //获取屏幕截图的灰度图，本质就是在原图基础上继续绘制灰色
    m_grayPixmap = m_systemInfo->getDesktopGrayScreen();
}

void ScreenCanvasWidget::initCanvas()
{
    //初始化一些指针：
    m_originPixmap = nullptr;
    m_grayPixmap = nullptr;

    this->setWindowTitle("ScreenCanvas");
    this->setWindowIcon(QIcon(":/reso/imgs/logo.svg"));

    // 窗口置顶 + 隐藏标题栏
//    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);

    //设置承托截图的背景画布所在窗口的大小，一般是全屏
    this->setFixedSize(QGuiApplication::primaryScreen()->size());
//    this->setFixedSize(1200,800);//暂时先设置这
}


//单例模式，初始化
//懒汉式
//ScreenCanvasWidget* ScreenCanvasWidget::m_singleCanvas = nullptr;
//ScreenCanvasWidget* ScreenCanvasWidget::getSingleCanvas()
//{
//    if(m_singleCanvas == nullptr)
//    {
//        m_singleCanvas = new ScreenCanvasWidget();
//    }
//    return m_singleCanvas;
//}

//当前Widget初始化显示出来的时候，就会调用 paintEvent
//当前Widget最小化后，点击任务栏重新打开时，也会执行 paintEvent
void ScreenCanvasWidget::paintEvent(QPaintEvent *event)
{
    qDebug() << "ScreenCanvasWidget paintEvent...";
    qDebug() <<"==> [log: 执行paintEvent时，是否已经获取：m_originPixmap = " << m_originPixmap << "]";
    qDebug() <<"==> [log: 执行paintEvent时，是否已经获取：m_grayPixmap = " << m_grayPixmap << "]";

    QPainter painter(this);
    painter.drawPixmap(QApplication::desktop()->rect(),*m_grayPixmap);

}









