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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *mainList;
    QVBoxLayout *verticalLayout;
    QLineEdit *listEdit;
    QLineEdit *symptomEdit;
    QPushButton *button;
    QListWidget *symptomsList;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(680, 217);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 661, 194));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mainList = new QListWidget(horizontalLayoutWidget);
        mainList->setObjectName(QString::fromUtf8("mainList"));

        horizontalLayout->addWidget(mainList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listEdit = new QLineEdit(horizontalLayoutWidget);
        listEdit->setObjectName(QString::fromUtf8("listEdit"));

        verticalLayout->addWidget(listEdit);

        symptomEdit = new QLineEdit(horizontalLayoutWidget);
        symptomEdit->setObjectName(QString::fromUtf8("symptomEdit"));

        verticalLayout->addWidget(symptomEdit);

        button = new QPushButton(horizontalLayoutWidget);
        button->setObjectName(QString::fromUtf8("button"));

        verticalLayout->addWidget(button);


        horizontalLayout->addLayout(verticalLayout);

        symptomsList = new QListWidget(horizontalLayoutWidget);
        symptomsList->setObjectName(QString::fromUtf8("symptomsList"));

        horizontalLayout->addWidget(symptomsList);

        GUIClass->setCentralWidget(centralWidget);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        button->setText(QApplication::translate("GUIClass", "Show Symptoms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
