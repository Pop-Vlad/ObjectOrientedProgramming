#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

#include "Controller.h"
#include "Observer.h"
#include <qmessagebox.h>

class GUI : public QMainWindow, public Observer {
	Q_OBJECT

private:

	Ui::GUIClass ui;

	std::string user;
	Controller* controller;

	void updateUI();
	void updateList();
	void reviewButtonUpdate();
	void scoreUpdate();
	void revise();

	void update() override;

	void connectSignals();

public:

	GUI(std::string user, Controller* controller, QWidget *parent = Q_NULLPTR);


};
