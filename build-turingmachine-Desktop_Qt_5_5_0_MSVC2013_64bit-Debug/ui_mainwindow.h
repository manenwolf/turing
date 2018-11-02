/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextBrowser *inputalphabet;
    QLabel *label;
    QTextBrowser *tapealphabet;
    QLabel *label_2;
    QTextBrowser *blank;
    QLabel *label_3;
    QTextBrowser *states;
    QTextBrowser *acceptingstates;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTextBrowser *startstate;
    QTextBrowser *transitions;
    QLabel *label_7;
    QLineEdit *input;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(796, 485);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 350, 231, 51));
        inputalphabet = new QTextBrowser(centralWidget);
        inputalphabet->setObjectName(QStringLiteral("inputalphabet"));
        inputalphabet->setGeometry(QRect(10, 40, 81, 221));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 91, 16));
        tapealphabet = new QTextBrowser(centralWidget);
        tapealphabet->setObjectName(QStringLiteral("tapealphabet"));
        tapealphabet->setGeometry(QRect(110, 40, 81, 221));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(120, 10, 71, 16));
        blank = new QTextBrowser(centralWidget);
        blank->setObjectName(QStringLiteral("blank"));
        blank->setGeometry(QRect(110, 300, 81, 41));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 270, 47, 13));
        states = new QTextBrowser(centralWidget);
        states->setObjectName(QStringLiteral("states"));
        states->setGeometry(QRect(220, 40, 91, 221));
        acceptingstates = new QTextBrowser(centralWidget);
        acceptingstates->setObjectName(QStringLiteral("acceptingstates"));
        acceptingstates->setGeometry(QRect(330, 40, 91, 221));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(220, 10, 47, 13));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(340, 10, 81, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(330, 280, 47, 13));
        startstate = new QTextBrowser(centralWidget);
        startstate->setObjectName(QStringLiteral("startstate"));
        startstate->setGeometry(QRect(330, 300, 81, 41));
        transitions = new QTextBrowser(centralWidget);
        transitions->setObjectName(QStringLiteral("transitions"));
        transitions->setGeometry(QRect(530, 40, 251, 221));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(530, 10, 71, 16));
        input = new QLineEdit(centralWidget);
        input->setObjectName(QStringLiteral("input"));
        input->setGeometry(QRect(280, 349, 121, 31));
        QFont font;
        font.setPointSize(12);
        input->setFont(font);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 350, 61, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 796, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        pushButton->setText(QApplication::translate("MainWindow", "browse", 0));
        label->setText(QApplication::translate("MainWindow", "inputAlphabet", 0));
        label_2->setText(QApplication::translate("MainWindow", "tapeAlphabet", 0));
        label_3->setText(QApplication::translate("MainWindow", "blank", 0));
        label_4->setText(QApplication::translate("MainWindow", "states", 0));
        label_5->setText(QApplication::translate("MainWindow", "acceptingstates", 0));
        label_6->setText(QApplication::translate("MainWindow", "startstate", 0));
        label_7->setText(QApplication::translate("MainWindow", "transitions", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "run", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
