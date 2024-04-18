/********************************************************************************
** Form generated from reading UI file 'trayiconwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAYICONWIDGET_H
#define UI_TRAYICONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrayiconWidget
{
public:

    void setupUi(QWidget *TrayiconWidget)
    {
        if (TrayiconWidget->objectName().isEmpty())
            TrayiconWidget->setObjectName(QString::fromUtf8("TrayiconWidget"));
        TrayiconWidget->resize(400, 300);

        retranslateUi(TrayiconWidget);

        QMetaObject::connectSlotsByName(TrayiconWidget);
    } // setupUi

    void retranslateUi(QWidget *TrayiconWidget)
    {
        TrayiconWidget->setWindowTitle(QCoreApplication::translate("TrayiconWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrayiconWidget: public Ui_TrayiconWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAYICONWIDGET_H
