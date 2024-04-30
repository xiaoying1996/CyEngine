/********************************************************************************
** Form generated from reading UI file 'EngineController.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENGINECONTROLLER_H
#define UI_ENGINECONTROLLER_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EngineControllerClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *ThreadModePoolBox;
    QPushButton *StartBtn;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *MinThreadBox;
    QComboBox *MaxThreadBox;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *CurrentEdit;
    QLineEdit *AliveEdit;
    QPushButton *StopBtn;
    QPushButton *TestBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EngineControllerClass)
    {
        if (EngineControllerClass->objectName().isEmpty())
            EngineControllerClass->setObjectName(QStringLiteral("EngineControllerClass"));
        EngineControllerClass->resize(800, 600);
        EngineControllerClass->setMinimumSize(QSize(800, 600));
        EngineControllerClass->setMaximumSize(QSize(800, 600));
        centralWidget = new QWidget(EngineControllerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 72, 15));
        ThreadModePoolBox = new QComboBox(centralWidget);
        ThreadModePoolBox->setObjectName(QStringLiteral("ThreadModePoolBox"));
        ThreadModePoolBox->setGeometry(QRect(100, 30, 87, 22));
        StartBtn = new QPushButton(centralWidget);
        StartBtn->setObjectName(QStringLiteral("StartBtn"));
        StartBtn->setGeometry(QRect(490, 30, 93, 28));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 30, 72, 15));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 60, 72, 15));
        MinThreadBox = new QComboBox(centralWidget);
        MinThreadBox->setObjectName(QStringLiteral("MinThreadBox"));
        MinThreadBox->setGeometry(QRect(280, 30, 87, 22));
        MaxThreadBox = new QComboBox(centralWidget);
        MaxThreadBox->setObjectName(QStringLiteral("MaxThreadBox"));
        MaxThreadBox->setGeometry(QRect(280, 60, 87, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 100, 72, 15));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 130, 72, 15));
        CurrentEdit = new QLineEdit(centralWidget);
        CurrentEdit->setObjectName(QStringLiteral("CurrentEdit"));
        CurrentEdit->setGeometry(QRect(280, 100, 81, 21));
        AliveEdit = new QLineEdit(centralWidget);
        AliveEdit->setObjectName(QStringLiteral("AliveEdit"));
        AliveEdit->setGeometry(QRect(280, 130, 81, 21));
        StopBtn = new QPushButton(centralWidget);
        StopBtn->setObjectName(QStringLiteral("StopBtn"));
        StopBtn->setGeometry(QRect(490, 70, 93, 28));
        TestBtn = new QPushButton(centralWidget);
        TestBtn->setObjectName(QStringLiteral("TestBtn"));
        TestBtn->setGeometry(QRect(660, 400, 112, 34));
        EngineControllerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EngineControllerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 30));
        EngineControllerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EngineControllerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        EngineControllerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EngineControllerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        EngineControllerClass->setStatusBar(statusBar);

        retranslateUi(EngineControllerClass);

        QMetaObject::connectSlotsByName(EngineControllerClass);
    } // setupUi

    void retranslateUi(QMainWindow *EngineControllerClass)
    {
        EngineControllerClass->setWindowTitle(QApplication::translate("EngineControllerClass", "EngineController", Q_NULLPTR));
        label->setText(QApplication::translate("EngineControllerClass", "\347\272\277\347\250\213\346\250\241\345\274\217", Q_NULLPTR));
        ThreadModePoolBox->clear();
        ThreadModePoolBox->insertItems(0, QStringList()
         << QApplication::translate("EngineControllerClass", "\345\215\225\347\272\277\347\250\213", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "\345\244\232\347\272\277\347\250\213", Q_NULLPTR)
        );
        StartBtn->setText(QApplication::translate("EngineControllerClass", "\345\274\200\345\247\213", Q_NULLPTR));
        label_2->setText(QApplication::translate("EngineControllerClass", "\346\234\200\345\260\217\347\272\277\347\250\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("EngineControllerClass", "\346\234\200\345\244\247\347\272\277\347\250\213", Q_NULLPTR));
        MinThreadBox->clear();
        MinThreadBox->insertItems(0, QStringList()
         << QApplication::translate("EngineControllerClass", "1", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "2", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "3", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "4", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "5", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "6", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "7", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "8", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "9", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "10", Q_NULLPTR)
        );
        MaxThreadBox->clear();
        MaxThreadBox->insertItems(0, QStringList()
         << QApplication::translate("EngineControllerClass", "20", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "19", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "18", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "17", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "16", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "15", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "14", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "13", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "12", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "11", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "10", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "9", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "8", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "7", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "6", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "5", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "4", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "3", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "2", Q_NULLPTR)
         << QApplication::translate("EngineControllerClass", "1", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("EngineControllerClass", "\347\271\201\345\277\231\347\272\277\347\250\213", Q_NULLPTR));
        label_5->setText(QApplication::translate("EngineControllerClass", "\345\255\230\346\264\273\347\272\277\347\250\213", Q_NULLPTR));
        CurrentEdit->setText(QApplication::translate("EngineControllerClass", "0", Q_NULLPTR));
        AliveEdit->setText(QApplication::translate("EngineControllerClass", "0", Q_NULLPTR));
        StopBtn->setText(QApplication::translate("EngineControllerClass", "\345\201\234\346\255\242", Q_NULLPTR));
        TestBtn->setText(QApplication::translate("EngineControllerClass", "\346\265\213\350\257\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EngineControllerClass: public Ui_EngineControllerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENGINECONTROLLER_H
