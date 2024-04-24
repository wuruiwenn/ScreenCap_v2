#include "trayiconwidget.h"
#include "ui_trayiconwidget.h"

TrayiconWidget::~TrayiconWidget()
{
    qDebug() << "TrayiconWidget析构.\n";
    delete screenCanvas;
    delete ui;
}

TrayiconWidget::TrayiconWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrayiconWidget)
{
    ui->setupUi(this);

    initTray();//初始化系统托盘相关，比如menu，action

    connect(tray,&QSystemTrayIcon::activated,this,&TrayiconWidget::trayActivatedHandler);
}
void TrayiconWidget::showMenu()
{
    trayMenu->show();
}
void TrayiconWidget::trayActivatedHandler(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
        case QSystemTrayIcon::Context:
            Tools::loger("系统托盘 单击右键 Context...");
            showMenu();
            break;
        case QSystemTrayIcon::Trigger:
            Tools::loger("系统托盘 单击左键 Trigger...");
            showScreenCanvas();
            break;
        default:
            break;
    }
}

void TrayiconWidget::showScreenCanvas()
{
    screenCanvas = ScreenCanvasWidget::getSingleCanvas();
    screenCanvas->show();
}


/*QSystemTrayIcon* tray;//系统托盘
QMenu* trayMenu;//菜单
QAction* exitAct;//退出选项，用于菜单
QAction* aboutAct;//关于选项，用于菜单
ScreenCanvasWidget* screenCanvas;//承托截图的背景画布类*/
void TrayiconWidget::initTray()
{
    //激活系统托盘，所需显示的截图背景画布
    screenCanvas = nullptr;

    //系统托盘上的菜单
    exitAct = new QAction("退出");
    aboutAct = new QAction("关于");
    trayMenu = new QMenu();
    trayMenu->addAction(exitAct);
    trayMenu->addSeparator();
    trayMenu->addAction(aboutAct);

    //系统托盘
    tray = new QSystemTrayIcon(this);
    tray->setContextMenu(trayMenu);
    tray->setIcon(QIcon(":/reso/imgs/tray_logo.svg"));
    tray->setToolTip("My Capture App");
    tray->show();//让托盘显示在系统任务栏上
}
