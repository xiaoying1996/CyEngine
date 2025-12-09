/********************************************************************************
** Form generated from reading UI file 'CyMapEditer.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CYMAPEDITER_H
#define UI_CYMAPEDITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CyMapEditerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QWidget *widget_3;
    QPushButton *NewMapBtn;
    QWidget *widget_5;
    QWidget *MapWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CyMapEditerClass)
    {
        if (CyMapEditerClass->objectName().isEmpty())
            CyMapEditerClass->setObjectName("CyMapEditerClass");
        CyMapEditerClass->resize(1600, 1200);
        centralWidget = new QWidget(CyMapEditerClass);
        centralWidget->setObjectName("centralWidget");
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName("widget_2");
        widget_2->setMaximumSize(QSize(350, 16777215));
        widget_2->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: white;"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setMaximumSize(QSize(16777215, 400));
        NewMapBtn = new QPushButton(widget_3);
        NewMapBtn->setObjectName("NewMapBtn");
        NewMapBtn->setGeometry(QRect(10, 20, 120, 30));
        NewMapBtn->setMinimumSize(QSize(120, 30));
        NewMapBtn->setMaximumSize(QSize(150, 40));

        verticalLayout->addWidget(widget_3);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName("widget_5");

        verticalLayout->addWidget(widget_5);


        horizontalLayout->addWidget(widget_2);

        MapWidget = new QWidget(centralWidget);
        MapWidget->setObjectName("MapWidget");
        MapWidget->setStyleSheet(QString::fromUtf8("border: 2px solid gray;\n"
"border-radius: 10px;\n"
"background-color: white;"));

        horizontalLayout->addWidget(MapWidget);

        CyMapEditerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CyMapEditerClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1600, 21));
        CyMapEditerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CyMapEditerClass);
        mainToolBar->setObjectName("mainToolBar");
        CyMapEditerClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CyMapEditerClass);
        statusBar->setObjectName("statusBar");
        CyMapEditerClass->setStatusBar(statusBar);

        retranslateUi(CyMapEditerClass);

        QMetaObject::connectSlotsByName(CyMapEditerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CyMapEditerClass)
    {
        CyMapEditerClass->setWindowTitle(QCoreApplication::translate("CyMapEditerClass", "CyMapEditer", nullptr));
        NewMapBtn->setText(QCoreApplication::translate("CyMapEditerClass", "\346\226\260\345\273\272\345\234\260\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CyMapEditerClass: public Ui_CyMapEditerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CYMAPEDITER_H
