#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"


#include "Repository.h"

class GUI : public QMainWindow {
	Q_OBJECT

private:

	Ui::GUIClass ui;

	Repository repository;

	void connectSignals();
	void populateList(std::vector<TimeInterval> elements);
	void filter();
	void computeTime();


public:

	GUI(Repository& repository, QWidget *parent = Q_NULLPTR);


};
