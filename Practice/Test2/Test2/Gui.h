#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

#include "Repository.h"

#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlabel.h>



class Test2 : public QMainWindow {

	Q_OBJECT

private:

	Ui::Test2Class ui;

	Repository repository;
	
	void init();
	void connectSignals();
	void populateList(std::vector<Task> elements);
	void filter();


public:

	Test2(const Repository& init_repository, QWidget *parent = Q_NULLPTR);


};
