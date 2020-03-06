/********************************************************************************
** Form generated from reading UI file 'Test1vs.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST1VS_H
#define UI_TEST1VS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test1vsClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *list;
    QVBoxLayout *verticalLayout;
    QLabel *manufacturerLabel;
    QLineEdit *input;
    QPushButton *button;
    QLineEdit *result;

    void setupUi(QMainWindow *Test1vsClass)
    {
        if (Test1vsClass->objectName().isEmpty())
            Test1vsClass->setObjectName(QString::fromUtf8("Test1vsClass"));
        Test1vsClass->resize(430, 228);
        centralWidget = new QWidget(Test1vsClass);
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
        manufacturerLabel = new QLabel(horizontalLayoutWidget);
        manufacturerLabel->setObjectName(QString::fromUtf8("manufacturerLabel"));

        verticalLayout->addWidget(manufacturerLabel);

        input = new QLineEdit(horizontalLayoutWidget);
        input->setObjectName(QString::fromUtf8("input"));

        verticalLayout->addWidget(input);

        button = new QPushButton(horizontalLayoutWidget);
        button->setObjectName(QString::fromUtf8("button"));

        verticalLayout->addWidget(button);

        result = new QLineEdit(horizontalLayoutWidget);
        result->setObjectName(QString::fromUtf8("result"));

        verticalLayout->addWidget(result);


        horizontalLayout->addLayout(verticalLayout);

        Test1vsClass->setCentralWidget(centralWidget);

        retranslateUi(Test1vsClass);

        QMetaObject::connectSlotsByName(Test1vsClass);
    } // setupUi

    void retranslateUi(QMainWindow *Test1vsClass)
    {
        Test1vsClass->setWindowTitle(QApplication::translate("Test1vsClass", "Test1vs", nullptr));
        manufacturerLabel->setText(QApplication::translate("Test1vsClass", "Manufacturer:", nullptr));
        button->setText(QApplication::translate("Test1vsClass", "Count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test1vsClass: public Ui_Test1vsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST1VS_H
