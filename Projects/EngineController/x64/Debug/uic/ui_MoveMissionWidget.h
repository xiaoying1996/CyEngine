/********************************************************************************
** Form generated from reading UI file 'MoveMissionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVEMISSIONWIDGET_H
#define UI_MOVEMISSIONWIDGET_H

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

class Ui_MoveMissionWidgetClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *ExecuterEdit;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *HumanBox;
    QComboBox *UavBox;
    QLabel *label_4;
    QTableWidget *MoveListWidget;
    QPushButton *SendBtn;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *LonEdit;
    QLineEdit *LatEdit;
    QLineEdit *AltEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MoveMissionWidgetClass)
    {
        if (MoveMissionWidgetClass->objectName().isEmpty())
            MoveMissionWidgetClass->setObjectName(QStringLiteral("MoveMissionWidgetClass"));
        MoveMissionWidgetClass->resize(900, 600);
        MoveMissionWidgetClass->setMinimumSize(QSize(900, 600));
        MoveMissionWidgetClass->setMaximumSize(QSize(900, 600));
        centralWidget = new QWidget(MoveMissionWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 120, 30));
        ExecuterEdit = new QLineEdit(centralWidget);
        ExecuterEdit->setObjectName(QStringLiteral("ExecuterEdit"));
        ExecuterEdit->setGeometry(QRect(200, 40, 150, 30));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 100, 120, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 160, 120, 30));
        HumanBox = new QComboBox(centralWidget);
        HumanBox->setObjectName(QStringLiteral("HumanBox"));
        HumanBox->setGeometry(QRect(200, 100, 150, 30));
        UavBox = new QComboBox(centralWidget);
        UavBox->setObjectName(QStringLiteral("UavBox"));
        UavBox->setGeometry(QRect(200, 160, 150, 30));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 40, 120, 30));
        MoveListWidget = new QTableWidget(centralWidget);
        if (MoveListWidget->columnCount() < 3)
            MoveListWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        MoveListWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        MoveListWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        MoveListWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (MoveListWidget->rowCount() < 4)
            MoveListWidget->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        MoveListWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        MoveListWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        MoveListWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        MoveListWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        MoveListWidget->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        MoveListWidget->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        MoveListWidget->setItem(0, 2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        MoveListWidget->setItem(1, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        MoveListWidget->setItem(1, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        MoveListWidget->setItem(1, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        MoveListWidget->setItem(2, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        MoveListWidget->setItem(2, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        MoveListWidget->setItem(2, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        MoveListWidget->setItem(3, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        MoveListWidget->setItem(3, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        MoveListWidget->setItem(3, 2, __qtablewidgetitem18);
        MoveListWidget->setObjectName(QStringLiteral("MoveListWidget"));
        MoveListWidget->setGeometry(QRect(420, 100, 411, 241));
        SendBtn = new QPushButton(centralWidget);
        SendBtn->setObjectName(QStringLiteral("SendBtn"));
        SendBtn->setGeometry(QRect(330, 400, 120, 30));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 240, 120, 30));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 280, 120, 30));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 320, 120, 30));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 360, 120, 30));
        LonEdit = new QLineEdit(centralWidget);
        LonEdit->setObjectName(QStringLiteral("LonEdit"));
        LonEdit->setGeometry(QRect(150, 280, 150, 30));
        LatEdit = new QLineEdit(centralWidget);
        LatEdit->setObjectName(QStringLiteral("LatEdit"));
        LatEdit->setGeometry(QRect(150, 320, 150, 30));
        AltEdit = new QLineEdit(centralWidget);
        AltEdit->setObjectName(QStringLiteral("AltEdit"));
        AltEdit->setGeometry(QRect(150, 360, 150, 30));
        MoveMissionWidgetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MoveMissionWidgetClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 900, 30));
        MoveMissionWidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MoveMissionWidgetClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MoveMissionWidgetClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MoveMissionWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MoveMissionWidgetClass->setStatusBar(statusBar);

        retranslateUi(MoveMissionWidgetClass);

        QMetaObject::connectSlotsByName(MoveMissionWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *MoveMissionWidgetClass)
    {
        MoveMissionWidgetClass->setWindowTitle(QApplication::translate("MoveMissionWidgetClass", "MoveMissionWidget", Q_NULLPTR));
        label->setText(QApplication::translate("MoveMissionWidgetClass", "\346\211\247\350\241\214\350\200\205:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MoveMissionWidgetClass", "\344\272\272\345\221\230:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MoveMissionWidgetClass", "\346\227\240\344\272\272\346\234\272:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MoveMissionWidgetClass", "\350\267\257\345\276\204\347\202\271:", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = MoveListWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MoveMissionWidgetClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = MoveListWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MoveMissionWidgetClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = MoveListWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MoveMissionWidgetClass", "\346\226\260\345\273\272\345\210\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = MoveListWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MoveMissionWidgetClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = MoveListWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MoveMissionWidgetClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = MoveListWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MoveMissionWidgetClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = MoveListWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MoveMissionWidgetClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));

        const bool __sortingEnabled = MoveListWidget->isSortingEnabled();
        MoveListWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = MoveListWidget->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MoveMissionWidgetClass", "115.00005", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = MoveListWidget->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("MoveMissionWidgetClass", "31.0001", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = MoveListWidget->item(0, 2);
        ___qtablewidgetitem9->setText(QApplication::translate("MoveMissionWidgetClass", "300", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = MoveListWidget->item(1, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("MoveMissionWidgetClass", "115.00007", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = MoveListWidget->item(1, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("MoveMissionWidgetClass", "31.0004", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = MoveListWidget->item(1, 2);
        ___qtablewidgetitem12->setText(QApplication::translate("MoveMissionWidgetClass", "100", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = MoveListWidget->item(2, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("MoveMissionWidgetClass", "115.00009", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = MoveListWidget->item(2, 1);
        ___qtablewidgetitem14->setText(QApplication::translate("MoveMissionWidgetClass", "31.0001", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = MoveListWidget->item(2, 2);
        ___qtablewidgetitem15->setText(QApplication::translate("MoveMissionWidgetClass", "200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = MoveListWidget->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("MoveMissionWidgetClass", "115.00001", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = MoveListWidget->item(3, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("MoveMissionWidgetClass", "31.0006", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = MoveListWidget->item(3, 2);
        ___qtablewidgetitem18->setText(QApplication::translate("MoveMissionWidgetClass", "300", Q_NULLPTR));
        MoveListWidget->setSortingEnabled(__sortingEnabled);

        SendBtn->setText(QApplication::translate("MoveMissionWidgetClass", "\344\270\213\345\217\221", Q_NULLPTR));
        label_5->setText(QApplication::translate("MoveMissionWidgetClass", "\345\275\223\345\211\215\344\275\215\347\275\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("MoveMissionWidgetClass", "\347\273\217\345\272\246:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MoveMissionWidgetClass", "\347\272\254\345\272\246:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MoveMissionWidgetClass", "\351\253\230\345\272\246:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MoveMissionWidgetClass: public Ui_MoveMissionWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVEMISSIONWIDGET_H
