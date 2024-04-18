
#include "SystemInfo.h"

SystemInfo::~SystemInfo(){
    delete screenInfo;
    qDebug() << "SystemInfo析构\n";
}

SystemInfo::SystemInfo(){
    screenInfo = QApplication::primaryScreen();
    m_originScreen = nullptr;
    m_grayScreen = nullptr;
}

int SystemInfo::getLogicalDPI(){
    return screenInfo->logicalDotsPerInch();
}

int SystemInfo::getPhysicalDPI(){
    return screenInfo->physicalDotsPerInch();
}
int SystemInfo::getDevicePixelRatio(){
    return screenInfo->devicePixelRatio();
}

QPixmap* SystemInfo::getDesktopScreen() {

    QDesktopWidget* desk = QApplication::desktop();
    QPixmap* pixRet = new QPixmap(
                screenInfo->grabWindow(desk->winId(),
                                       0,0,
                                       desk->size().width(),
                                       desk->size().height())
                );
    qDebug() << "获取桌面原图的截图...pixRet = " << pixRet ;
    QString filepath = QGuiApplication::applicationDirPath() + "/origin_desktop_screen.jpg";
    qDebug() << "filepath = " << filepath;
    pixRet->save(filepath);

    m_originScreen = pixRet;
    return pixRet;
}

QPixmap* SystemInfo::getDesktopGrayScreen() {
    if(!m_originScreen){
        Tools::loger("还未获取原图，不能直接获取灰色图...");
        return nullptr;
    }
    //定义一个设备，用来画灰色图
    //初始化为屏幕截图的原图
    QPixmap* pixRet = new QPixmap(*m_originScreen);//先用原图初始化一个灰色图的内容，然后在上面绘制灰色

    //需要绘制的内容，就是一层透明白色
    QPixmap blurPixmap(m_originScreen->size());  // 桌面图片上的灰色层，当然我这里的灰色本质就是白色，在原图的基础上绘制一层带透明度的白色，就相当于灰色了
    blurPixmap.fill(QColor(255, 255, 255, 0.5 * 255));

    //画笔
    QPainter painter(pixRet);//关联设备
    painter.drawPixmap(pixRet->rect(),blurPixmap);

    QString filepath = QGuiApplication::applicationDirPath()+"/gray_desktop_screen.jpg";
    pixRet->save(filepath);

    qDebug() << "获取桌面原图的截图的灰色图...pixRet = " << pixRet;
    m_grayScreen = pixRet;

    return m_grayScreen;
}
