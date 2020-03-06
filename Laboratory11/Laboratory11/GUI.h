#pragma once

#include <QtWidgets/QMainWindow>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qlabel.h>
#include <qformlayout.h>
#include <qmessagebox.h>

#include <functional>
#include <stdlib.h>

#include "Controller.h"
#include "Validator.h"
#include "Drawings.h"



class GUI : public QWidget {

	Q_OBJECT

private:

	Controller* controller;
	Validator* validator;

	QPushButton* file_location;
	QPushButton* mylist_location;
	QPushButton* modeA_button;
	QPushButton* modeB_button;

	QListWidget* fragments_list;
	QLineEdit* id_edit;
	QLineEdit* size_edit;
	QLineEdit* infection_edit;
	QLineEdit* microfragments_edit;
	QLineEdit* photograph_edit;
	QPushButton* add_button;
	QPushButton* update_button;
	QPushButton* delete_button;
	PieChart* infection_chart;
	Photograph* photograph;

	QLineEdit* current_fragment;
	QPushButton* next_button;
	QPushButton* save_button;
	QLineEdit* size_search_edit;
	QLineEdit* microfragments_search_edit;
	QPushButton* search_button;
	QListWidget* mylist;

	void initGUI();
	void connectSignals();
	void populateFragmentsList();

	int getSelectedFragment() const;
	void listDataFromIndex();

	void switchToModeA();
	void switchToModeB();
	void addFragment();
	void updateFragment();
	void deleteFragmant();


public:

	GUI(Controller* input_controller, QWidget *parent = Q_NULLPTR);


};
