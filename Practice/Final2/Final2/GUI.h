#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

#include "Controller.h"
#include "Observer.h"

class GUI : public QMainWindow, public Observer {
	Q_OBJECT

private:

	Ui::GUIClass ui;

	Controller* controller;
	std::string user;
	int score;
	std::vector<int> answered;

	void connectSignals();
	void populateList();

	void updateSelected();
	void answer();

public:

	GUI(Controller* controller, std::string user, QWidget *parent = Q_NULLPTR);

	void update() override;


};
