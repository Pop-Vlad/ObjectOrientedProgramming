/********************************************************************************
** Form generated from reading UI file 'DevelopGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVELOPGUI_H
#define UI_DEVELOPGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DevelopGUI
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QPushButton *saveButton;

    void setupUi(QWidget *DevelopGUI)
    {
        if (DevelopGUI->objectName().isEmpty())
            DevelopGUI->setObjectName(QString::fromUtf8("DevelopGUI"));
        DevelopGUI->resize(282, 247);
        verticalLayoutWidget = new QWidget(DevelopGUI);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 258, 223));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);

        saveButton = new QPushButton(verticalLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        verticalLayout->addWidget(saveButton);


        retranslateUi(DevelopGUI);

        QMetaObject::connectSlotsByName(DevelopGUI);
    } // setupUi

    void retranslateUi(QWidget *DevelopGUI)
    {
        DevelopGUI->setWindowTitle(QApplication::translate("DevelopGUI", "DevelopGUI", nullptr));
        saveButton->setText(QApplication::translate("DevelopGUI", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DevelopGUI: public Ui_DevelopGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVELOPGUI_H
