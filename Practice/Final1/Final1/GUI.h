#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include <qmessagebox.h>

#include "IssueRepository.h"
#include "Observer.h"

class GUI : public QMainWindow, public Observer {
	Q_OBJECT

private:

	Ui::GUIClass ui;
	std::string user;
	IssueRepository* repository;

	void populateList();
	void connectSignals();
	void selectedItemHandler();

	void add();
	void remove();
	void resolve();

	void update() override;

public:

	GUI(const std::string& user_name, const std::string& user_type, IssueRepository* init_repo, QWidget *parent = Q_NULLPTR);


};
