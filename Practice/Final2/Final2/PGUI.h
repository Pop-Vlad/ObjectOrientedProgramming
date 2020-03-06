#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PGUI.h"

#include <qmessagebox.h>

#include "Controller.h"
#include "Subject.h"

class PGUI : public QMainWindow, public Subject {
	Q_OBJECT

private:

	Ui::PGUI ui;

	Controller* controller;
	std::string user;

	void connectSignals();
	void populateList();

	void addQuestion();

public:

	PGUI(Controller* controller, QWidget *parent = Q_NULLPTR);


};
