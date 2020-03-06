#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DevelopGUI.h"
#include <qfiledialog.h>
#include <fstream>

class DevelopGUI : public QMainWindow {
	Q_OBJECT

private:

	Ui::DevelopGUI ui;
	std::string content;

	void connectSignals();
	void save();

public:

	DevelopGUI(std::string content, QWidget *parent = Q_NULLPTR);

};
