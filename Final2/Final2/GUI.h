#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

#include "Controller.h"
#include "Observer.h"
#include <qmessagebox.h>
#include "DevelopGUI.h"

class GUI : public QMainWindow, public Observer {
	Q_OBJECT

private:

	Ui::GUIClass ui;

	std::string user;
	Controller* controller;

	void populateList();
	void connectSignals();
	void addIdea();
	void savePlot();
	void develop();
	void updateDevelopButton();
	void revise();
	void updateReviseButton();
	void update() override;

public:

	GUI(std::string init_user, Controller* init_contrloller, QWidget *parent = Q_NULLPTR);


};
