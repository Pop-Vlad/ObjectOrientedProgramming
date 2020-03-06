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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GUIClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tab;
    QWidget *modeA;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *mainList;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *idLabel;
    QLineEdit *idEdit;
    QLabel *sizeLabel;
    QLineEdit *sizeEdit;
    QLabel *infectionLabel;
    QLineEdit *infectionEdit;
    QLabel *microfragmentsLabel;
    QLineEdit *microfragmentsEdit;
    QLabel *photographLabel;
    QLineEdit *photographEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *updateButton;
    QPushButton *deleteButton;
    QPushButton *undoButton;
    QPushButton *redoButton;
    QWidget *modeB;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_2;
    QLabel *currentLabel;
    QLineEdit *currentEdit;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *saveButton;
    QPushButton *nextButton;
    QFormLayout *formLayout_3;
    QLabel *searchSizeLabel;
    QLabel *searchMicrofragmentstLabel;
    QLineEdit *searchSizeEdit;
    QLineEdit *searchMicrofragmetnsEdit;
    QPushButton *searchButton;
    QPushButton *showMylistButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *fileButton;
    QPushButton *mylistButton;

    void setupUi(QMainWindow *GUIClass)
    {
        if (GUIClass->objectName().isEmpty())
            GUIClass->setObjectName(QString::fromUtf8("GUIClass"));
        GUIClass->resize(521, 432);
        centralWidget = new QWidget(GUIClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tab = new QTabWidget(centralWidget);
        tab->setObjectName(QString::fromUtf8("tab"));
        tab->setGeometry(QRect(10, 40, 501, 381));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        tab->setFont(font);
        modeA = new QWidget();
        modeA->setObjectName(QString::fromUtf8("modeA"));
        horizontalLayoutWidget_2 = new QWidget(modeA);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 479, 332));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        mainList = new QListWidget(horizontalLayoutWidget_2);
        mainList->setObjectName(QString::fromUtf8("mainList"));

        horizontalLayout_2->addWidget(mainList);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        idLabel = new QLabel(horizontalLayoutWidget_2);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        idLabel->setFont(font);
        idLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, idLabel);

        idEdit = new QLineEdit(horizontalLayoutWidget_2);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, idEdit);

        sizeLabel = new QLabel(horizontalLayoutWidget_2);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));
        sizeLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, sizeLabel);

        sizeEdit = new QLineEdit(horizontalLayoutWidget_2);
        sizeEdit->setObjectName(QString::fromUtf8("sizeEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sizeEdit);

        infectionLabel = new QLabel(horizontalLayoutWidget_2);
        infectionLabel->setObjectName(QString::fromUtf8("infectionLabel"));
        infectionLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, infectionLabel);

        infectionEdit = new QLineEdit(horizontalLayoutWidget_2);
        infectionEdit->setObjectName(QString::fromUtf8("infectionEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, infectionEdit);

        microfragmentsLabel = new QLabel(horizontalLayoutWidget_2);
        microfragmentsLabel->setObjectName(QString::fromUtf8("microfragmentsLabel"));
        microfragmentsLabel->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, microfragmentsLabel);

        microfragmentsEdit = new QLineEdit(horizontalLayoutWidget_2);
        microfragmentsEdit->setObjectName(QString::fromUtf8("microfragmentsEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, microfragmentsEdit);

        photographLabel = new QLabel(horizontalLayoutWidget_2);
        photographLabel->setObjectName(QString::fromUtf8("photographLabel"));
        photographLabel->setFont(font);

        formLayout->setWidget(5, QFormLayout::LabelRole, photographLabel);

        photographEdit = new QLineEdit(horizontalLayoutWidget_2);
        photographEdit->setObjectName(QString::fromUtf8("photographEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, photographEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout);


        verticalLayout->addLayout(formLayout);

        addButton = new QPushButton(horizontalLayoutWidget_2);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        updateButton = new QPushButton(horizontalLayoutWidget_2);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));

        verticalLayout->addWidget(updateButton);

        deleteButton = new QPushButton(horizontalLayoutWidget_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        undoButton = new QPushButton(horizontalLayoutWidget_2);
        undoButton->setObjectName(QString::fromUtf8("undoButton"));

        verticalLayout->addWidget(undoButton);

        redoButton = new QPushButton(horizontalLayoutWidget_2);
        redoButton->setObjectName(QString::fromUtf8("redoButton"));

        verticalLayout->addWidget(redoButton);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        tab->addTab(modeA, QString());
        modeB = new QWidget();
        modeB->setObjectName(QString::fromUtf8("modeB"));
        verticalLayoutWidget = new QWidget(modeB);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 192, 188));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        currentLabel = new QLabel(verticalLayoutWidget);
        currentLabel->setObjectName(QString::fromUtf8("currentLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, currentLabel);

        currentEdit = new QLineEdit(verticalLayoutWidget);
        currentEdit->setObjectName(QString::fromUtf8("currentEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, currentEdit);


        verticalLayout_4->addLayout(formLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        saveButton = new QPushButton(verticalLayoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_5->addWidget(saveButton);

        nextButton = new QPushButton(verticalLayoutWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));

        horizontalLayout_5->addWidget(nextButton);


        verticalLayout_4->addLayout(horizontalLayout_5);

        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        searchSizeLabel = new QLabel(verticalLayoutWidget);
        searchSizeLabel->setObjectName(QString::fromUtf8("searchSizeLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, searchSizeLabel);

        searchMicrofragmentstLabel = new QLabel(verticalLayoutWidget);
        searchMicrofragmentstLabel->setObjectName(QString::fromUtf8("searchMicrofragmentstLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, searchMicrofragmentstLabel);

        searchSizeEdit = new QLineEdit(verticalLayoutWidget);
        searchSizeEdit->setObjectName(QString::fromUtf8("searchSizeEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, searchSizeEdit);

        searchMicrofragmetnsEdit = new QLineEdit(verticalLayoutWidget);
        searchMicrofragmetnsEdit->setObjectName(QString::fromUtf8("searchMicrofragmetnsEdit"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, searchMicrofragmetnsEdit);


        verticalLayout_4->addLayout(formLayout_3);

        searchButton = new QPushButton(verticalLayoutWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        verticalLayout_4->addWidget(searchButton);

        showMylistButton = new QPushButton(verticalLayoutWidget);
        showMylistButton->setObjectName(QString::fromUtf8("showMylistButton"));

        verticalLayout_4->addWidget(showMylistButton);

        tab->addTab(modeB, QString());
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 158, 28));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        fileButton = new QPushButton(horizontalLayoutWidget);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));
        fileButton->setFont(font);

        horizontalLayout_3->addWidget(fileButton);

        mylistButton = new QPushButton(horizontalLayoutWidget);
        mylistButton->setObjectName(QString::fromUtf8("mylistButton"));
        mylistButton->setFont(font);

        horizontalLayout_3->addWidget(mylistButton);

        GUIClass->setCentralWidget(centralWidget);

        retranslateUi(GUIClass);

        tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *GUIClass)
    {
        GUIClass->setWindowTitle(QApplication::translate("GUIClass", "GUI", nullptr));
        idLabel->setText(QApplication::translate("GUIClass", "Id:", nullptr));
        sizeLabel->setText(QApplication::translate("GUIClass", "Size:", nullptr));
        infectionLabel->setText(QApplication::translate("GUIClass", "Infection:", nullptr));
        microfragmentsLabel->setText(QApplication::translate("GUIClass", "Microfrag:", nullptr));
        photographLabel->setText(QApplication::translate("GUIClass", "Photo:", nullptr));
        addButton->setText(QApplication::translate("GUIClass", "Add", nullptr));
        updateButton->setText(QApplication::translate("GUIClass", "Update", nullptr));
        deleteButton->setText(QApplication::translate("GUIClass", "Delete", nullptr));
        undoButton->setText(QApplication::translate("GUIClass", "Undo", nullptr));
        redoButton->setText(QApplication::translate("GUIClass", "Redo", nullptr));
        tab->setTabText(tab->indexOf(modeA), QApplication::translate("GUIClass", "Mode A", nullptr));
        currentLabel->setText(QApplication::translate("GUIClass", "Current", nullptr));
        saveButton->setText(QApplication::translate("GUIClass", "Save", nullptr));
        nextButton->setText(QApplication::translate("GUIClass", "Next", nullptr));
        searchSizeLabel->setText(QApplication::translate("GUIClass", "Size:", nullptr));
        searchMicrofragmentstLabel->setText(QApplication::translate("GUIClass", "Microfragments:", nullptr));
        searchButton->setText(QApplication::translate("GUIClass", "Search", nullptr));
        showMylistButton->setText(QApplication::translate("GUIClass", "Show Mylist", nullptr));
        tab->setTabText(tab->indexOf(modeB), QApplication::translate("GUIClass", "Mode B", nullptr));
        fileButton->setText(QApplication::translate("GUIClass", "File", nullptr));
        mylistButton->setText(QApplication::translate("GUIClass", "MyList", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUIClass: public Ui_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
