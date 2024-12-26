/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QGraphicsView *graphicsView;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *test1_text;
    QLabel *test5_text;
    QLabel *label_6;
    QLabel *test3_text;
    QLabel *test4_text;
    QLabel *test2_text;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1275, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(410, 20, 221, 221));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(30, 300, 901, 241));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 190, 101, 51));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 210, 161, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(290, 210, 31, 16));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 130, 171, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 90, 51, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 60, 51, 16));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(100, 60, 113, 24));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 90, 113, 24));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 20, 281, 31));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(890, 20, 61, 31));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(890, 60, 61, 31));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(890, 100, 61, 31));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(890, 140, 61, 31));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(890, 180, 61, 31));
        test1_text = new QLabel(centralwidget);
        test1_text->setObjectName(QString::fromUtf8("test1_text"));
        test1_text->setGeometry(QRect(980, 20, 231, 31));
        test5_text = new QLabel(centralwidget);
        test5_text->setObjectName(QString::fromUtf8("test5_text"));
        test5_text->setGeometry(QRect(980, 180, 201, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(890, 220, 281, 31));
        test3_text = new QLabel(centralwidget);
        test3_text->setObjectName(QString::fromUtf8("test3_text"));
        test3_text->setGeometry(QRect(980, 100, 201, 31));
        test4_text = new QLabel(centralwidget);
        test4_text->setObjectName(QString::fromUtf8("test4_text"));
        test4_text->setGeometry(QRect(980, 140, 251, 31));
        test2_text = new QLabel(centralwidget);
        test2_text->setObjectName(QString::fromUtf8("test2_text"));
        test2_text->setGeometry(QRect(980, 60, 201, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1275, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\270\320\267\320\263\320\276\321\202\320\276\320\262\320\273\320\265\320\275\320\276:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260:", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \320\266\320\265\320\273\320\265\320\267\320\275\320\276\320\263\320\276 \320\273\320\270\321\201\321\202\320\260:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "test1", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "test2", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "test3", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "test4", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "test5", nullptr));
        test1_text->setText(QCoreApplication::translate("MainWindow", "10 20; 15 15; 40 40", nullptr));
        test5_text->setText(QCoreApplication::translate("MainWindow", "10 20; 15 15; 40 85; 10 10; 5 5; 5 5", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\266\320\265\320\273\320\265\320\267\320\275\320\276\320\263\320\276 \320\273\320\270\321\201\321\202\320\260: 100 50 ", nullptr));
        test3_text->setText(QCoreApplication::translate("MainWindow", "10 20; 15 15; 40 40; 30 30; 30 30", nullptr));
        test4_text->setText(QCoreApplication::translate("MainWindow", "30 30; 40 40; 15 45; 5 5; 10 10; 10 20; 20 20", nullptr));
        test2_text->setText(QCoreApplication::translate("MainWindow", "10 20; 15 15; 85 40; 5 5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
