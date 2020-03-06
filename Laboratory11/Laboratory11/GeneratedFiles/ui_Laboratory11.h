/********************************************************************************
** Form generated from reading UI file 'Laboratory11.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABORATORY11_H
#define UI_LABORATORY11_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Laboratory11Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Laboratory11Class)
    {
        if (Laboratory11Class->objectName().isEmpty())
            Laboratory11Class->setObjectName(QString::fromUtf8("Laboratory11Class"));
        Laboratory11Class->resize(600, 400);
        menuBar = new QMenuBar(Laboratory11Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Laboratory11Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Laboratory11Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Laboratory11Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Laboratory11Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Laboratory11Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Laboratory11Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Laboratory11Class->setStatusBar(statusBar);

        retranslateUi(Laboratory11Class);

        QMetaObject::connectSlotsByName(Laboratory11Class);
    } // setupUi

    void retranslateUi(QMainWindow *Laboratory11Class)
    {
        Laboratory11Class->setWindowTitle(QApplication::translate("Laboratory11Class", "Laboratory11", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Laboratory11Class: public Ui_Laboratory11Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABORATORY11_H
