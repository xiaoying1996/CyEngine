/********************************************************************************
** Form generated from reading UI file 'MissionChooser.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSIONCHOOSER_H
#define UI_MISSIONCHOOSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MissionChooserClass
{
public:
    QWidget *centralWidget;
    QPushButton *MoveMissionBtn;
    QPushButton *AttackMissionBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MissionChooserClass)
    {
        if (MissionChooserClass->objectName().isEmpty())
            MissionChooserClass->setObjectName(QStringLiteral("MissionChooserClass"));
        MissionChooserClass->resize(900, 600);
        MissionChooserClass->setMinimumSize(QSize(900, 600));
        MissionChooserClass->setMaximumSize(QSize(900, 600));
        centralWidget = new QWidget(MissionChooserClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MoveMissionBtn = new QPushButton(centralWidget);
        MoveMissionBtn->setObjectName(QStringLiteral("MoveMissionBtn"));
        MoveMissionBtn->setGeometry(QRect(50, 20, 112, 34));
        AttackMissionBtn = new QPushButton(centralWidget);
        AttackMissionBtn->setObjectName(QStringLiteral("AttackMissionBtn"));
        AttackMissionBtn->setGeometry(QRect(50, 70, 112, 34));
        MissionChooserClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MissionChooserClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 30));
        MissionChooserClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MissionChooserClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MissionChooserClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MissionChooserClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MissionChooserClass->setStatusBar(statusBar);

        retranslateUi(MissionChooserClass);

        QMetaObject::connectSlotsByName(MissionChooserClass);
    } // setupUi

    void retranslateUi(QMainWindow *MissionChooserClass)
    {
        MissionChooserClass->setWindowTitle(QApplication::translate("MissionChooserClass", "MissionChooser", Q_NULLPTR));
        MoveMissionBtn->setText(QApplication::translate("MissionChooserClass", "\347\247\273\345\212\250", Q_NULLPTR));
        AttackMissionBtn->setText(QApplication::translate("MissionChooserClass", "\346\224\273\345\207\273", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MissionChooserClass: public Ui_MissionChooserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONCHOOSER_H
