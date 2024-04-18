//#include "screenbackwidget.h"
//#include "ui_screenbackwidget.h"

//ScreenBackWidget::~ScreenBackWidget()
//{
//    delete ui;
//}

//ScreenBackWidget::ScreenBackWidget(QImage img)
//    :backImg(img)
//{
//    ui->setupUi(this);

//    qDebug() << "screenBackImg 2 = "<< backImg << "\n";

//    this->setWindowState(Qt::WindowFullScreen);//将窗口设置为全屏模式，即占据整个屏幕显示
//    this->setWindowFlags(Qt::Tool | Qt::X11BypassWindowManagerHint);//不在任务栏显示该窗口的图标

//    this->setCursor(Qt::CrossCursor); //设置鼠标光标为十字光标
//    this->grabKeyboard();//捕获键盘事件，使得窗口可以接收键盘按键事件
//}


//void ScreenBackWidget::paintEvent(QPaintEvent *event)
//{
//    qDebug() << "=========> paintEvent...\n";

//    qDebug() << "screenBackImg 3 = "<< backImg << "\n";


//    QPainter painter(this);
//    painter.drawImage(QRect(QPoint(0,0),this->size()),this->backImg);

//    //设置ESC，Enter说明
//    QFont myFont("微软雅黑",20);
//    painter.setFont(myFont);
//    painter.setPen(Qt::red);
//    painter.drawText(this->width()/2,100,"ESC取消截图内容，Enter截取内容复制到剪切板");
//}
