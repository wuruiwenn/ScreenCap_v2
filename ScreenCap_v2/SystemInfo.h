#ifndef SYSTEMINFO_H
#define SYSTEMINFO_H

#include"defines.h"


class SystemInfo{
public:
    SystemInfo();
    ~SystemInfo();
public:
    int getLogicalDPI();
    int getPhysicalDPI();
    int getDevicePixelRatio();

    QPixmap* getDesktopScreen();
    QPixmap* getDesktopGrayScreen();

    QPixmap* m_originScreen;//桌面当前截图原图
    QPixmap* m_grayScreen;//桌面当前截图的灰化图

private:
    QScreen* screenInfo;
};


#endif // SYSTEMINFO_H
