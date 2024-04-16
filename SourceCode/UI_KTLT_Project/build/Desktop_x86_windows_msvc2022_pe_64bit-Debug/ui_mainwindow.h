/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *loginLabel;
    QLineEdit *usernameLabel;
    QLineEdit *passwordLabel;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_Cancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 0, 414, 547));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/background/background_login.png);\n"
"border-radius: 20px;"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(150, 20, 371, 501));
        label_2->setMouseTracking(false);
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 139);\n"
"border-radius:15px;"));
        loginLabel = new QLabel(centralwidget);
        loginLabel->setObjectName("loginLabel");
        loginLabel->setGeometry(QRect(270, 80, 111, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(28);
        font.setBold(true);
        loginLabel->setFont(font);
        loginLabel->setAutoFillBackground(false);
        loginLabel->setStyleSheet(QString::fromUtf8("color:rgba(255,255,255,210)"));
        loginLabel->setScaledContents(false);
        usernameLabel = new QLineEdit(centralwidget);
        usernameLabel->setObjectName("usernameLabel");
        usernameLabel->setEnabled(true);
        usernameLabel->setGeometry(QRect(220, 180, 251, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("MS Gothic")});
        font1.setPointSize(12);
        font1.setItalic(false);
        usernameLabel->setFont(font1);
        usernameLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"border-bottom: 2px solid rgba(110,120,125,255);\n"
"color:rgba(255,255,255,230);\n"
"padding-bottom:7px;"));
        usernameLabel->setMaxLength(32767);
        usernameLabel->setEchoMode(QLineEdit::Normal);
        usernameLabel->setDragEnabled(false);
        usernameLabel->setClearButtonEnabled(false);
        passwordLabel = new QLineEdit(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(220, 270, 251, 41));
        passwordLabel->setFont(font1);
        passwordLabel->setStyleSheet(QString::fromUtf8("background-color: rgba(0,0,0,0);\n"
"border: none;\n"
"border-bottom: 2px solid rgba(110,120,125,255);\n"
"color:rgba(255,255,255,230);\n"
"padding-bottom:7px;"));
        passwordLabel->setEchoMode(QLineEdit::NoEcho);
        pushButton_Login = new QPushButton(centralwidget);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setGeometry(QRect(330, 370, 161, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("MS Gothic")});
        font2.setPointSize(12);
        pushButton_Login->setFont(font2);
        pushButton_Login->setStyleSheet(QString::fromUtf8("QPushButton#pushButton{\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(50, 60, 60, 150), stop: 1 rgba(40, 90, 0, 226));\n"
"\n"
"color:rgba(255, 255, 255, 210);\n"
"\n"
"border-radius:5px;\n"
"}\n"
"QPushButton#pushButton:hover{\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(40, 67, 98, 219), stop: 1 rgba(105, 118, 132, 226));\n"
"}\n"
"\n"
"QPushButton #pushButton:pressed{\n"
"\n"
"padding-left: 10px;\n"
"\n"
"padding-top:10px;\n"
"\n"
"background-color:rgba(105, 118, 132, 200);\n"
"}"));
        pushButton_Cancel = new QPushButton(centralwidget);
        pushButton_Cancel->setObjectName("pushButton_Cancel");
        pushButton_Cancel->setGeometry(QRect(180, 370, 141, 50));
        pushButton_Cancel->setFont(font2);
        pushButton_Cancel->setStyleSheet(QString::fromUtf8("QPushButton#pushButton{\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(50, 60, 60, 150), stop: 1 rgba(40, 90, 0, 226));\n"
"\n"
"}\n"
"QPushButton#pushButton:hover{\n"
"\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.505682, x2:1, y2:0.477, stop:0 rgba(40, 67, 98, 219), stop: 1 rgba(105, 118, 132, 226));\n"
"}\n"
"\n"
"QPushButton #pushButton:pressed{\n"
"\n"
"padding-left: 10px;\n"
"\n"
"padding-top:10px;\n"
"\n"
"background-color:rgba(105, 118, 132, 200);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        loginLabel->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        usernameLabel->setText(QString());
        usernameLabel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        passwordLabel->setInputMask(QString());
        passwordLabel->setText(QString());
        passwordLabel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("MainWindow", "Log In", nullptr));
        pushButton_Cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
