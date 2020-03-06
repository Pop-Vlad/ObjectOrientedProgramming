/********************************************************************************
** Form generated from reading UI file 'StatisticsGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSGUI_H
#define UI_STATISTICSGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsGUI
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StatisticsGUI)
    {
        if (StatisticsGUI->objectName().isEmpty())
            StatisticsGUI->setObjectName(QString::fromUtf8("StatisticsGUI"));
        StatisticsGUI->resize(400, 300);
        menuBar = new QMenuBar(StatisticsGUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        StatisticsGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StatisticsGUI);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        StatisticsGUI->addToolBar(mainToolBar);
        centralWidget = new QWidget(StatisticsGUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        StatisticsGUI->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(StatisticsGUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        StatisticsGUI->setStatusBar(statusBar);

        retranslateUi(StatisticsGUI);

        QMetaObject::connectSlotsByName(StatisticsGUI);
    } // setupUi

    void retranslateUi(QMainWindow *StatisticsGUI)
    {
        StatisticsGUI->setWindowTitle(QApplication::translate("StatisticsGUI", "StatisticsGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsGUI: public Ui_StatisticsGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSGUI_H
