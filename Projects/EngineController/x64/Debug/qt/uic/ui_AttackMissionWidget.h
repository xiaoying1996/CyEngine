/********************************************************************************
** Form generated from reading UI file 'AttackMissionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTACKMISSIONWIDGET_H
#define UI_ATTACKMISSIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttackMissionWidgetClass
{
public:
    QWidget *centralWidget;
    QPushButton *SendBtn;
    QComboBox *HumanBox;
    QLabel *label_8;
    QLineEdit *LatEdit;
    QLabel *label_5;
    QLineEdit *LonEdit;
    QLabel *label_3;
    QLineEdit *AltEdit;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *ExecuterEdit;
    QLabel *label_2;
    QComboBox *UavBox;
    QLabel *label_7;
    QTableWidget *TargetListWidget;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AttackMissionWidgetClass)
    {
        if (AttackMissionWidgetClass->objectName().isEmpty())
            AttackMissionWidgetClass->setObjectName(QStringLiteral("AttackMissionWidgetClass"));
        AttackMissionWidgetClass->resize(1200, 900);
        AttackMissionWidgetClass->setMinimumSize(QSize(1200, 900));
        AttackMissionWidgetClass->setMaximumSize(QSize(1200, 900));
        centralWidget = new QWidget(AttackMissionWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SendBtn = new QPushButton(centralWidget);
        SendBtn->setObjectName(QStringLiteral("SendBtn"));
        SendBtn->setGeometry(QRect(360, 560, 120, 30));
        HumanBox = new QComboBox(centralWidget);
        HumanBox->setObjectName(QStringLiteral("HumanBox"));
        HumanBox->setGeometry(QRect(240, 100, 150, 30));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(100, 360, 120, 30));
        LatEdit = new QLineEdit(centralWidget);
        LatEdit->setObjectName(QStringLiteral("LatEdit"));
        LatEdit->setGeometry(QRect(190, 320, 150, 30));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 240, 120, 30));
        LonEdit = new QLineEdit(centralWidget);
        LonEdit->setObjectName(QStringLiteral("LonEdit"));
        LonEdit->setGeometry(QRect(190, 280, 150, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 160, 120, 30));
        AltEdit = new QLineEdit(centralWidget);
        AltEdit->setObjectName(QStringLiteral("AltEdit"));
        AltEdit->setGeometry(QRect(190, 360, 150, 30));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 120, 30));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 280, 120, 30));
        ExecuterEdit = new QLineEdit(centralWidget);
        ExecuterEdit->setObjectName(QStringLiteral("ExecuterEdit"));
        ExecuterEdit->setGeometry(QRect(240, 40, 150, 30));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 100, 120, 30));
        UavBox = new QComboBox(centralWidget);
        UavBox->setObjectName(QStringLiteral("UavBox"));
        UavBox->setGeometry(QRect(240, 160, 150, 30));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 320, 120, 30));
        TargetListWidget = new QTableWidget(centralWidget);
        TargetListWidget->setObjectName(QStringLiteral("TargetListWidget"));
        TargetListWidget->setGeometry(QRect(470, 70, 650, 421));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(470, 30, 120, 30));
        AttackMissionWidgetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AttackMissionWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 30));
        AttackMissionWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AttackMissionWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AttackMissionWidgetClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AttackMissionWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AttackMissionWidgetClass->setStatusBar(statusBar);

        retranslateUi(AttackMissionWidgetClass);

        QMetaObject::connectSlotsByName(AttackMissionWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *AttackMissionWidgetClass)
    {
        AttackMissionWidgetClass->setWindowTitle(QApplication::translate("AttackMissionWidgetClass", "AttackMissionWidget", Q_NULLPTR));
        SendBtn->setText(QApplication::translate("AttackMissionWidgetClass", "\344\270\213\345\217\221", Q_NULLPTR));
        label_8->setText(QApplication::translate("AttackMissionWidgetClass", "\351\253\230\345\272\246:", Q_NULLPTR));
        label_5->setText(QApplication::translate("AttackMissionWidgetClass", "\345\275\223\345\211\215\344\275\215\347\275\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("AttackMissionWidgetClass", "\346\227\240\344\272\272\346\234\272:", Q_NULLPTR));
        label->setText(QApplication::translate("AttackMissionWidgetClass", "\346\211\247\350\241\214\350\200\205:", Q_NULLPTR));
        label_6->setText(QApplication::translate("AttackMissionWidgetClass", "\347\273\217\345\272\246:", Q_NULLPTR));
        label_2->setText(QApplication::translate("AttackMissionWidgetClass", "\344\272\272\345\221\230:", Q_NULLPTR));
        label_7->setText(QApplication::translate("AttackMissionWidgetClass", "\347\272\254\345\272\246:", Q_NULLPTR));
        label_4->setText(QApplication::translate("AttackMissionWidgetClass", "\347\233\256\346\240\207\345\210\227\350\241\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AttackMissionWidgetClass: public Ui_AttackMissionWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTACKMISSIONWIDGET_H
