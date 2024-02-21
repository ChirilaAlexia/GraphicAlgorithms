/********************************************************************************
** Form generated from reading UI file 'LuxemburgFinal.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUXEMBURGFINAL_H
#define UI_LUXEMBURGFINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LuxemburgFinalClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LuxemburgFinalClass)
    {
        if (LuxemburgFinalClass->objectName().isEmpty())
            LuxemburgFinalClass->setObjectName("LuxemburgFinalClass");
        LuxemburgFinalClass->resize(600, 400);
        menuBar = new QMenuBar(LuxemburgFinalClass);
        menuBar->setObjectName("menuBar");
        LuxemburgFinalClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LuxemburgFinalClass);
        mainToolBar->setObjectName("mainToolBar");
        LuxemburgFinalClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(LuxemburgFinalClass);
        centralWidget->setObjectName("centralWidget");
        LuxemburgFinalClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(LuxemburgFinalClass);
        statusBar->setObjectName("statusBar");
        LuxemburgFinalClass->setStatusBar(statusBar);

        retranslateUi(LuxemburgFinalClass);

        QMetaObject::connectSlotsByName(LuxemburgFinalClass);
    } // setupUi

    void retranslateUi(QMainWindow *LuxemburgFinalClass)
    {
        LuxemburgFinalClass->setWindowTitle(QCoreApplication::translate("LuxemburgFinalClass", "LuxemburgFinal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LuxemburgFinalClass: public Ui_LuxemburgFinalClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUXEMBURGFINAL_H
