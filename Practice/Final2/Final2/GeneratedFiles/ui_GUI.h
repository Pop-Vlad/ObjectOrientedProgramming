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
    QListWidget *QuestionsList;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *answerEdit;
    QPushButton *answerButton;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLabel *score;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(476, 272);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 401, 215));
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

        verticalLayout->addWidget(label);

        QuestionsList = new QListWidget(horizontalLayoutWidget);
        QuestionsList->setObjectName(QString::fromUtf8("QuestionsList"));

        verticalLayout->addWidget(QuestionsList);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        answerEdit = new QLineEdit(horizontalLayoutWidget);
        answerEdit->setObjectName(QString::fromUtf8("answerEdit"));

        verticalLayout_2->addWidget(answerEdit);

        answerButton = new QPushButton(horizontalLayoutWidget);
        answerButton->setObjectName(QString::fromUtf8("answerButton"));

        verticalLayout_2->addWidget(answerButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        score = new QLabel(horizontalLayoutWidget);
        score->setObjectName(QString::fromUtf8("score"));

        verticalLayout_2->addWidget(score);


        horizontalLayout->addLayout(verticalLayout_2);

        GUIClass->setCentralWidget(centralWidget);

        retranslateUi(GUIClass);

        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        label->setText(QApplication::translate("GUIClass", "Questions:", nullptr));
        label_2->setText(QApplication::translate("GUIClass", "Answer:", nullptr));
        answerButton->setText(QApplication::translate("GUIClass", "Answer", nullptr));
        label_3->setText(QApplication::translate("GUIClass", "Score:", nullptr));
        score->setText(QApplication::translate("GUIClass", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
