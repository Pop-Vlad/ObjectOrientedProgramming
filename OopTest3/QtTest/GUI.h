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
	void populateList(std::vector<Document> documents);
	void search();
	void getBestMatch();


public:

	GUI(Repository& init_repository, QWidget *parent = Q_NULLPTR);


};
