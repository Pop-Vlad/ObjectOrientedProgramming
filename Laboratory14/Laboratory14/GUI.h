#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"

#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <qfiledialog.h>
#include <qshortcut.h>

#include <functional>
#include <stdlib.h>

#include "Controller.h"
#include "Validator.h"
#include "Drawings.h"
#include "TableModel.h"



class GUI : public QMainWindow {

	Q_OBJECT

private:

	Ui::GUIClass ui;

	Controller* controller;
	Validator* validator;

	void initGUI();
	void connectSignals();
	void populateFragmentsList();

	int getSelectedFragment() const;
	void listDataFromIndex();

	void changeFile();
	void changeMylist();
	void switchMode();
	void addFragment();
	void updateFragment();
	void deleteFragmant();
	void undo();
	void redo();

	void nextFragment();
	void saveFragment();
	void search();
	void showSearchResults(const std::vector<AnomalousFragment>& results);
	void showMylist();


public:

	GUI(Controller* input_controller, QWidget *parent = Q_NULLPTR);


};
