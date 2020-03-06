#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Laboratory11.h"

class Laboratory11 : public QMainWindow
{
	Q_OBJECT

public:
	Laboratory11(QWidget *parent = Q_NULLPTR);

private:
	Ui::Laboratory11Class ui;
};
