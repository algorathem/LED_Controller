/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *labelPotValue;
    QSlider *horizontalSlider;
    QPushButton *pushButtonToggle;
    QCheckBox *darkModeCheckBox;
    QLabel *label;
    QLabel *labelStatus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelPotValue = new QLabel(centralwidget);
        labelPotValue->setObjectName(QString::fromUtf8("labelPotValue"));
        labelPotValue->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #333333;  /* dark gray */\n"
"    font-size: 16px;\n"
"    font-family: Arial, sans-serif;\n"
"}"));

        gridLayout->addWidget(labelPotValue, 4, 4, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 8px;\n"
"    background: #b0b0b0;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* Style for QSlider handle */\n"
"QSlider::handle:horizontal {\n"
"    background: #4CAF50;\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -5px 0;\n"
"    border-radius: 9px;\n"
"}"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 4, 3, 1, 1);

        pushButtonToggle = new QPushButton(centralwidget);
        pushButtonToggle->setObjectName(QString::fromUtf8("pushButtonToggle"));
        pushButtonToggle->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4CAF50;  /* green */\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #45a049;  /* darker green on hover */\n"
"}"));

        gridLayout->addWidget(pushButtonToggle, 3, 4, 1, 1);

        darkModeCheckBox = new QCheckBox(centralwidget);
        darkModeCheckBox->setObjectName(QString::fromUtf8("darkModeCheckBox"));

        gridLayout->addWidget(darkModeCheckBox, 3, 5, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName(QString::fromUtf8("labelStatus"));
        labelStatus->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #333333;  /* dark gray */\n"
"    font-size: 16px;\n"
"    font-family: Arial, sans-serif;\n"
"}"));

        gridLayout->addWidget(labelStatus, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        labelPotValue->setText(QCoreApplication::translate("MainWindow", "PWM", nullptr));
        pushButtonToggle->setText(QCoreApplication::translate("MainWindow", "Potentiometer", nullptr));
        darkModeCheckBox->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Slider", nullptr));
        labelStatus->setText(QCoreApplication::translate("MainWindow", "Input Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
