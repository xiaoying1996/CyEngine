/********************************************************************************
** Form generated from reading UI file 'SignUpWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWIDGET_H
#define UI_SIGNUPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignInWidgetClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *NameEdit;
    QLineEdit *NumEdit;
    QLineEdit *EmailEdit;
    QLineEdit *PasswordEdit;
    QLineEdit *Password2Edit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *WarnLabel;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SignInWidgetClass)
    {
        if (SignInWidgetClass->objectName().isEmpty())
            SignInWidgetClass->setObjectName(QStringLiteral("SignInWidgetClass"));
        SignInWidgetClass->resize(520, 750);
        SignInWidgetClass->setMinimumSize(QSize(520, 750));
        SignInWidgetClass->setMaximumSize(QSize(600, 750));
        centralWidget = new QWidget(SignInWidgetClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 200, 120, 30));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 280, 120, 30));
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 360, 120, 30));
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 440, 120, 30));
        label_4->setFont(font);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 520, 120, 30));
        label_5->setFont(font);
        NameEdit = new QLineEdit(centralWidget);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));
        NameEdit->setGeometry(QRect(220, 200, 180, 30));
        NumEdit = new QLineEdit(centralWidget);
        NumEdit->setObjectName(QStringLiteral("NumEdit"));
        NumEdit->setGeometry(QRect(220, 280, 180, 30));
        EmailEdit = new QLineEdit(centralWidget);
        EmailEdit->setObjectName(QStringLiteral("EmailEdit"));
        EmailEdit->setGeometry(QRect(220, 360, 180, 30));
        PasswordEdit = new QLineEdit(centralWidget);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setGeometry(QRect(220, 440, 180, 30));
        Password2Edit = new QLineEdit(centralWidget);
        Password2Edit->setObjectName(QStringLiteral("Password2Edit"));
        Password2Edit->setGeometry(QRect(220, 520, 180, 30));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 590, 100, 30));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 590, 100, 30));
        WarnLabel = new QLabel(centralWidget);
        WarnLabel->setObjectName(QStringLiteral("WarnLabel"));
        WarnLabel->setGeometry(QRect(220, 680, 281, 20));
        SignInWidgetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SignInWidgetClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SignInWidgetClass->setStatusBar(statusBar);

        retranslateUi(SignInWidgetClass);

        QMetaObject::connectSlotsByName(SignInWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *SignInWidgetClass)
    {
        SignInWidgetClass->setWindowTitle(QApplication::translate("SignInWidgetClass", "SignInWidget", Q_NULLPTR));
        label->setText(QApplication::translate("SignInWidgetClass", "\346\230\265\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("SignInWidgetClass", "\346\211\213\346\234\272\345\217\267", Q_NULLPTR));
        label_3->setText(QApplication::translate("SignInWidgetClass", "\351\202\256\347\256\261", Q_NULLPTR));
        label_4->setText(QApplication::translate("SignInWidgetClass", "\345\257\206\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("SignInWidgetClass", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SignInWidgetClass", "\347\241\256\350\256\244", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SignInWidgetClass", "\345\217\226\346\266\210", Q_NULLPTR));
        WarnLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignInWidgetClass: public Ui_SignInWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWIDGET_H
