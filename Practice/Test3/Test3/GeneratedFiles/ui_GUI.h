/********************************************************************************
** Form generated from reading UI file 'GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *list;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *filterLabel;
    QLineEdit *filterEdit;
    QSpacerItem *verticalSpacer;
    QLabel *timeLabel;
    QLineEdit *timeEdit;
    QPushButton *button;
    QLineEdit *resultEdit;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(474, 258);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 456, 235));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        list = new QListWidget(horizontalLayoutWidget);
        list->setObjectName(QString::fromUtf8("list"));

        horizontalLayout->addWidget(list);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        filterLabel = new QLabel(horizontalLayoutWidget);
        filterLabel->setObjectName(QString::fromUtf8("filterLabel"));

        verticalLayout->addWidget(filterLabel);

        filterEdit = new QLineEdit(horizontalLayoutWidget);
        filterEdit->setObjectName(QString::fromUtf8("filterEdit"));

        verticalLayout->addWidget(filterEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        timeLabel = new QLabel(horizontalLayoutWidget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        verticalLayout->addWidget(timeLabel);

        timeEdit = new QLineEdit(horizontalLayoutWidget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));

        verticalLayout->addWidget(timeEdit);

        button = new QPushButton(horizontalLayoutWidget);
        button->setObjectName(QString::fromUtf8("button"));

        verticalLayout->addWidget(button);

        resultEdit = new QLineEdit(horizontalLayoutWidget);
        resultEdit->setObjectName(QString::fromUtf8("resultEdit"));

        verticalLayout->addWidget(resultEdit);


        horizontalLayout->addLayout(verticalLayout);

        GUIClass->setCentralWidget(centralWidget);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        filterLabel->setText(QApplication::translate("GUIClass", "Filter by precipitation:", nullptr));
        timeLabel->setText(QApplication::translate("GUIClass", "Compute the total tme for some weater", nullptr));
        button->setText(QApplication::translate("GUIClass", "Compute total", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
