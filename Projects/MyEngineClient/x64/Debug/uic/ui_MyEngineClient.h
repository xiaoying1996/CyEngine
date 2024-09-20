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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyEngineClientClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QComboBox *AccountBox;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *PasswordEdit;
    QPushButton *SignInBtn;
    QPushButton *SignUpBtn;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyEngineClientClass)
    {
        if (MyEngineClientClass->objectName().isEmpty())
            MyEngineClientClass->setObjectName(QStringLiteral("MyEngineClientClass"));
        MyEngineClientClass->resize(900, 600);
        MyEngineClientClass->setMinimumSize(QSize(900, 600));
        MyEngineClientClass->setMaximumSize(QSize(900, 600));
        QIcon icon;
        icon.addFile(QStringLiteral("C:/Users/material/pic/login/title2.png"), QSize(), QIcon::Normal, QIcon::Off);
        MyEngineClientClass->setWindowIcon(icon);
        centralWidget = new QWidget(MyEngineClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 200, 120, 30));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        AccountBox = new QComboBox(centralWidget);
        AccountBox->setObjectName(QStringLiteral("AccountBox"));
        AccountBox->setGeometry(QRect(230, 200, 180, 30));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(25, -30, 301, 381));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 260, 120, 30));
        label_3->setFont(font);
        PasswordEdit = new QLineEdit(centralWidget);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setGeometry(QRect(230, 260, 180, 30));
        SignInBtn = new QPushButton(centralWidget);
        SignInBtn->setObjectName(QStringLiteral("SignInBtn"));
        SignInBtn->setGeometry(QRect(100, 350, 120, 30));
        SignUpBtn = new QPushButton(centralWidget);
        SignUpBtn->setObjectName(QStringLiteral("SignUpBtn"));
        SignUpBtn->setGeometry(QRect(280, 350, 120, 30));
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
        label->setText(QApplication::translate("MyEngineClientClass", "\350\264\246\345\217\267", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("MyEngineClientClass", "\345\257\206\347\240\201", Q_NULLPTR));
        SignInBtn->setText(QApplication::translate("MyEngineClientClass", "\347\231\273\345\275\225", Q_NULLPTR));
        SignUpBtn->setText(QApplication::translate("MyEngineClientClass", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyEngineClientClass: public Ui_MyEngineClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYENGINECLIENT_H
