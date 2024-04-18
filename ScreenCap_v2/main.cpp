#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFont myFont("Microsoft Yahei",10);//设置字体
    a.setFont(myFont);

    MainWidget w;
    w.resize(1200,800);
    w.setWindowTitle("ScreenCap_v2");

//    w.setWindowFlags(Qt::CustomizeWindowHint);
    w.show();
    return a.exec();
}
