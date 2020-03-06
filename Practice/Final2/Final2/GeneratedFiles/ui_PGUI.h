/********************************************************************************
** Form generated from reading UI file 'PGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PGUI_H
#define UI_PGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PGUI
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *QuestionsList;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *idEdit;
    QLabel *label_3;
    QLineEdit *textEdit;
    QLabel *label_4;
    QLineEdit *answerEdit;
    QLabel *label_5;
    QLineEdit *scoreEdit;
    QPushButton *addButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PGUI)
    {
        if (PGUI->objectName().isEmpty())
            PGUI->setObjectName(QString::fromUtf8("PGUI"));
        PGUI->resize(426, 272);
        horizontalLayoutWidget = new QWidget(PGUI);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 401, 253));
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

        idEdit = new QLineEdit(horizontalLayoutWidget);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        verticalLayout_2->addWidget(idEdit);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        textEdit = new QLineEdit(horizontalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        answerEdit = new QLineEdit(horizontalLayoutWidget);
        answerEdit->setObjectName(QString::fromUtf8("answerEdit"));

        verticalLayout_2->addWidget(answerEdit);

        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        scoreEdit = new QLineEdit(horizontalLayoutWidget);
        scoreEdit->setObjectName(QString::fromUtf8("scoreEdit"));

        verticalLayout_2->addWidget(scoreEdit);

        addButton = new QPushButton(horizontalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_2->addWidget(addButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(PGUI);

        QMetaObject::connectSlotsByName(PGUI);
    } // setupUi

    void retranslateUi(QWidget *PGUI)
    {
        PGUI->setWindowTitle(QApplication::translate("PGUI", "PGUI", nullptr));
        label->setText(QApplication::translate("PGUI", "Question:", nullptr));
        label_2->setText(QApplication::translate("PGUI", "Id:", nullptr));
        label_3->setText(QApplication::translate("PGUI", "Text:", nullptr));
        label_4->setText(QApplication::translate("PGUI", "Answer:", nullptr));
        label_5->setText(QApplication::translate("PGUI", "Score:", nullptr));
        addButton->setText(QApplication::translate("PGUI", "ADD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PGUI: public Ui_PGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PGUI_H
