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

    QPixmap* m_originScreen;
    QPixmap* m_grayScreen;

private:
    QScreen* screenInfo;
};


#endif // SYSTEMINFO_H
