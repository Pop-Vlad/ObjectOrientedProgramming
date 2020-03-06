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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test2Class
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *list;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *priorityLabel;
    QLineEdit *priorityEdit;
    QPushButton *button;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Test2Class)
    {
        if (Test2Class->objectName().isEmpty())
            Test2Class->setObjectName(QString::fromUtf8("Test2Class"));
        Test2Class->resize(418, 229);
        centralWidget = new QWidget(Test2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 399, 194));
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
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        priorityLabel = new QLabel(horizontalLayoutWidget);
        priorityLabel->setObjectName(QString::fromUtf8("priorityLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        priorityLabel->setFont(font);

        verticalLayout->addWidget(priorityLabel);

        priorityEdit = new QLineEdit(horizontalLayoutWidget);
        priorityEdit->setObjectName(QString::fromUtf8("priorityEdit"));

        verticalLayout->addWidget(priorityEdit);

        button = new QPushButton(horizontalLayoutWidget);
        button->setObjectName(QString::fromUtf8("button"));
        button->setFont(font);

        verticalLayout->addWidget(button);


        horizontalLayout->addLayout(verticalLayout);

        Test2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Test2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Test2Class->setStatusBar(statusBar);

        retranslateUi(Test2Class);

        QMetaObject::connectSlotsByName(Test2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Test2Class)
    {
        Test2Class->setWindowTitle(QApplication::translate("Test2Class", "Test2", nullptr));
        priorityLabel->setText(QApplication::translate("Test2Class", "Priority:", nullptr));
        button->setText(QApplication::translate("Test2Class", "Show by priority", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test2Class: public Ui_Test2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
