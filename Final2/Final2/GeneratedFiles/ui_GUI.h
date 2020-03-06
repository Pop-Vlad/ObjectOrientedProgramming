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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *ideasList;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *descriptionEdit;
    QLabel *label_2;
    QLineEdit *actEdit;
    QPushButton *addButton;
    QPushButton *reviseButton;
    QPushButton *developButton;
    QPushButton *saveButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(600, 400);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 399, 204));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ideasList = new QListWidget(horizontalLayoutWidget);
        ideasList->setObjectName(QString::fromUtf8("ideasList"));

        horizontalLayout->addWidget(ideasList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        descriptionEdit = new QLineEdit(horizontalLayoutWidget);
        descriptionEdit->setObjectName(QString::fromUtf8("descriptionEdit"));

        verticalLayout->addWidget(descriptionEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        actEdit = new QLineEdit(horizontalLayoutWidget);
        actEdit->setObjectName(QString::fromUtf8("actEdit"));

        verticalLayout->addWidget(actEdit);

        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        reviseButton = new QPushButton(horizontalLayoutWidget);
        reviseButton->setObjectName(QString::fromUtf8("reviseButton"));

        verticalLayout->addWidget(reviseButton);

        developButton = new QPushButton(horizontalLayoutWidget);
        developButton->setObjectName(QString::fromUtf8("developButton"));

        verticalLayout->addWidget(developButton);

        saveButton = new QPushButton(horizontalLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout->addWidget(saveButton);


        horizontalLayout->addLayout(verticalLayout);

        GUIClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUIClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GUIClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GUIClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GUIClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUIClass->setStatusBar(statusBar);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        label->setText(QApplication::translate("GUIClass", "Description:", nullptr));
        label_2->setText(QApplication::translate("GUIClass", "Act:", nullptr));
        addButton->setText(QApplication::translate("GUIClass", "Add", nullptr));
        reviseButton->setText(QApplication::translate("GUIClass", "Revise", nullptr));
        developButton->setText(QApplication::translate("GUIClass", "Develop", nullptr));
        saveButton->setText(QApplication::translate("GUIClass", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
