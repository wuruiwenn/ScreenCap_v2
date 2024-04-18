/********************************************************************************
** Form generated from reading UI file 'screenbackwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENBACKWIDGET_H
#define UI_SCREENBACKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScreenBackWidget
{
public:

    void setupUi(QWidget *ScreenBackWidget)
    {
        if (ScreenBackWidget->objectName().isEmpty())
            ScreenBackWidget->setObjectName(QString::fromUtf8("ScreenBackWidget"));
        ScreenBackWidget->resize(400, 300);

        retranslateUi(ScreenBackWidget);

        QMetaObject::connectSlotsByName(ScreenBackWidget);
    } // setupUi

    void retranslateUi(QWidget *ScreenBackWidget)
    {
        ScreenBackWidget->setWindowTitle(QCoreApplication::translate("ScreenBackWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScreenBackWidget: public Ui_ScreenBackWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENBACKWIDGET_H
