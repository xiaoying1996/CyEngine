/********************************************************************************
** Form generated from reading UI file 'MyEngineClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYENGINECLIENT_H
#define UI_MYENGINECLIENT_H

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

class Ui_MyEngineClientClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyEngineClientClass)
    {
        if (MyEngineClientClass->objectName().isEmpty())
            MyEngineClientClass->setObjectName(QStringLiteral("MyEngineClientClass"));
        MyEngineClientClass->resize(600, 400);
        menuBar = new QMenuBar(MyEngineClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyEngineClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyEngineClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyEngineClientClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyEngineClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyEngineClientClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyEngineClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyEngineClientClass->setStatusBar(statusBar);

        retranslateUi(MyEngineClientClass);

        QMetaObject::connectSlotsByName(MyEngineClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyEngineClientClass)
    {
        MyEngineClientClass->setWindowTitle(QApplication::translate("MyEngineClientClass", "MyEngineClient", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyEngineClientClass: public Ui_MyEngineClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYENGINECLIENT_H
