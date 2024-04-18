#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::~MainWidget()
{
    qDebug() << "MainWidget析构.\n";
    delete trayWidget;
    delete ui;
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);

    initMainUI();//初始化主界面 UI


    connect(toCapTrayBtn,&QPushButton::clicked,this,&MainWidget::toCapTrayBtnClickedHandler);


}

void MainWidget::initMainUI()
{
    trayWidget = nullptr;

    topWidget = new QWidget(this);
    //topWidget->setStyleSheet("border:3px solid red;");

    //2个截图功能按钮
    toCapBtn = new QPushButton("To Capture",topWidget);
    toCapTrayBtn = new QPushButton("Capture丨Tray",topWidget);

    //设置按钮的显示style
    QFile btnStyleFile(":/reso/myBtnStyle/myBtnStyle.qss");
    btnStyleFile.open(QFile::ReadOnly);
    QString btnStyle = tr(btnStyleFile.readAll());
    toCapTrayBtn->setStyleSheet(btnStyle);
    toCapBtn->setStyleSheet(btnStyle);




    //3个弹簧
    spacerLeft = new QSpacerItem(900,50,QSizePolicy::Expanding,QSizePolicy::Fixed);
    spacerMid = new QSpacerItem(10,50,QSizePolicy::Minimum,QSizePolicy::Fixed);
    spacerRight = new QSpacerItem(10,50,QSizePolicy::Fixed,QSizePolicy::Fixed);

    QHBoxLayout* hLayout = new QHBoxLayout(topWidget);
    hLayout->addSpacerItem(spacerLeft);
    hLayout->addWidget(toCapBtn);
    hLayout->addSpacerItem(spacerMid);
    hLayout->addWidget(toCapTrayBtn);
    hLayout->addSpacerItem(spacerRight);

    //分割线
//    lineBtn = new QPushButton(topWidget);
//    lineBtn->setGeometry(0,90,this->width(),2);
//    lineBtn->setStyleSheet("background-color:rgb(249,222,224);");
//    lineBtn->setFocusPolicy(Qt::NoFocus);

//    QVBoxLayout* vLayout = new QVBoxLayout(this);
//    vLayout->addWidget(topWidget);
//    vLayout->addWidget(lineBtn);

    //真的是做梦也没想到要这样设置

}

void MainWidget::toCapTrayBtnClickedHandler(){
    trayWidget = new TrayiconWidget(this);

//    this->showMinimized();//主窗口最小化

//    QScreen* screen = QApplication::screenAt(QCursor().pos());
//    QImage screenBackImg = screen->grabWindow(0).toImage();

//    qDebug() << "screenBackImg 1 = "<< screenBackImg << "\n";
//    screenBackWidget = new ScreenBackWidget(screenBackImg);

//    screenBackWidget->show();
    //这里是用新的一个窗口放置背景图片，
    //其实可以在原Dialog上，直接update触发paintEvent事件
}

//设置主窗口内部的widget随着主窗口放大缩小而等比例变化
void MainWidget::resizeEvent(QResizeEvent *event)
{
    qDebug() << "MainWidget resize...\n";
    topWidget->setFixedWidth(this->height()*0.3);
    topWidget->setFixedWidth(this->width()*1);


//    设置按钮等比例放大缩小
//    toCapBtn->setFixedSize(160,50);
//    int left_margin = qMax(this->width() - 160,40);
//    toCapBtn->move(left_margin-40,20);
}



