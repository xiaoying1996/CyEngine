/********************************************************************************
** Form generated from reading UI file 'PicPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICPLAYER_H
#define UI_PICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PicPlayerClass
{
public:
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PicPlayerClass)
    {
        if (PicPlayerClass->objectName().isEmpty())
            PicPlayerClass->setObjectName(QStringLiteral("PicPlayerClass"));
        PicPlayerClass->resize(600, 400);
        centralWidget = new QWidget(PicPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PicPlayerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PicPlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PicPlayerClass->setStatusBar(statusBar);

        retranslateUi(PicPlayerClass);

        QMetaObject::connectSlotsByName(PicPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *PicPlayerClass)
    {
        PicPlayerClass->setWindowTitle(QApplication::translate("PicPlayerClass", "PicPlayer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PicPlayerClass: public Ui_PicPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICPLAYER_H
