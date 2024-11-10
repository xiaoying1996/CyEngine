/********************************************************************************
** Form generated from reading UI file 'HCLWidhet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HCLWIDHET_H
#define UI_HCLWIDHET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HCLWidhetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HCLWidhetClass)
    {
        if (HCLWidhetClass->objectName().isEmpty())
            HCLWidhetClass->setObjectName(QStringLiteral("HCLWidhetClass"));
        HCLWidhetClass->resize(600, 400);
        menuBar = new QMenuBar(HCLWidhetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        HCLWidhetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HCLWidhetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HCLWidhetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HCLWidhetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HCLWidhetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HCLWidhetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HCLWidhetClass->setStatusBar(statusBar);

        retranslateUi(HCLWidhetClass);

        QMetaObject::connectSlotsByName(HCLWidhetClass);
    } // setupUi

    void retranslateUi(QMainWindow *HCLWidhetClass)
    {
        HCLWidhetClass->setWindowTitle(QApplication::translate("HCLWidhetClass", "HCLWidhet", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HCLWidhetClass: public Ui_HCLWidhetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HCLWIDHET_H
