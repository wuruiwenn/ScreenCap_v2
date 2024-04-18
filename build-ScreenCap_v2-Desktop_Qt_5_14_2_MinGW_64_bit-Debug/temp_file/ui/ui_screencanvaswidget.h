/********************************************************************************
** Form generated from reading UI file 'screencanvaswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENCANVASWIDGET_H
#define UI_SCREENCANVASWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenCanvasWidget
{
public:

    void setupUi(QWidget *ScreenCanvasWidget)
    {
        if (ScreenCanvasWidget->objectName().isEmpty())
            ScreenCanvasWidget->setObjectName(QString::fromUtf8("ScreenCanvasWidget"));
        ScreenCanvasWidget->resize(400, 300);

        retranslateUi(ScreenCanvasWidget);

        QMetaObject::connectSlotsByName(ScreenCanvasWidget);
    } // setupUi

    void retranslateUi(QWidget *ScreenCanvasWidget)
    {
        ScreenCanvasWidget->setWindowTitle(QCoreApplication::translate("ScreenCanvasWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenCanvasWidget: public Ui_ScreenCanvasWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENCANVASWIDGET_H
