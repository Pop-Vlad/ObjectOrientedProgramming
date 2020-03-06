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
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *issuesList;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *issueEdit;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *resolveButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(421, 238);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 401, 220));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        issuesList = new QListWidget(horizontalLayoutWidget);
        issuesList->setObjectName(QString::fromUtf8("issuesList"));

        verticalLayout->addWidget(issuesList);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        issueEdit = new QLineEdit(horizontalLayoutWidget);
        issueEdit->setObjectName(QString::fromUtf8("issueEdit"));

        verticalLayout_2->addWidget(issueEdit);

        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_2->addWidget(addButton);

        removeButton = new QPushButton(horizontalLayoutWidget);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));

        verticalLayout_2->addWidget(removeButton);

        resolveButton = new QPushButton(horizontalLayoutWidget);
        resolveButton->setObjectName(QString::fromUtf8("resolveButton"));

        verticalLayout_2->addWidget(resolveButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        GUIClass->setCentralWidget(centralWidget);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        label->setText(QApplication::translate("GUIClass", "Issues:", nullptr));
        addButton->setText(QApplication::translate("GUIClass", "Add", nullptr));
        removeButton->setText(QApplication::translate("GUIClass", "Remove", nullptr));
        resolveButton->setText(QApplication::translate("GUIClass", "Resolve", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
