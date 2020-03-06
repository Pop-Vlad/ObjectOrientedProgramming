#pragma once

#include <QMainWindow>
#include "ui_StatisticsGUI.h"

#include "Controller.h"

class StatisticsGUI : public QMainWindow {
	Q_OBJECT

private:

	Ui::StatisticsGUI ui;

	Controller* controller;

public:

	StatisticsGUI(QWidget *parent = Q_NULLPTR);


};
