#pragma once

#include "GUI.h"
#include "ui_SeniorGui.h"

class SeniorGui : public GUI
{
	Q_OBJECT

public:
	SeniorGui(QWidget *parent = Q_NULLPTR);
	~SeniorGui();

private:
	Ui::SeniorGui ui;
};
