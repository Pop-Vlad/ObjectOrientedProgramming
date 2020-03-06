#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test1vs.h"

#include "Repository.h"

#include <qboxlayout.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>
#include <qlistwidget.h>



class Test1vs : public QMainWindow {
	Q_OBJECT

private:

	Ui::Test1vsClass ui;

	Repository repository;

	void init();
	void connectSignals();
	void polupateList();
	void buttonHandler();

public:

	Test1vs(Repository init_repository, QWidget *parent = Q_NULLPTR);


};
