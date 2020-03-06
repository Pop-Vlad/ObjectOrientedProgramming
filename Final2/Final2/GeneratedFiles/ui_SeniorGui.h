/********************************************************************************
** Form generated from reading UI file 'SeniorGui.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENIORGUI_H
#define UI_SENIORGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <gui.h>

QT_BEGIN_NAMESPACE

class Ui_SeniorGui
{
public:

    void setupUi(GUI *SeniorGui)
    {
        if (SeniorGui->objectName().isEmpty())
            SeniorGui->setObjectName(QString::fromUtf8("SeniorGui"));
        SeniorGui->resize(400, 300);

        retranslateUi(SeniorGui);

        QMetaObject::connectSlotsByName(SeniorGui);
    } // setupUi

    void retranslateUi(GUI *SeniorGui)
    {
        SeniorGui->setWindowTitle(QApplication::translate("SeniorGui", "SeniorGui", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeniorGui: public Ui_SeniorGui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENIORGUI_H
