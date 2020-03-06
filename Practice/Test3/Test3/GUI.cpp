#include "GUI.h"



GUI::GUI(Repository& repository, QWidget *parent) : repository(repository), QMainWindow(parent) {
	ui.setupUi(this);
	this->connectSignals();
	this->populateList(this->repository.getElements());
}


void GUI::connectSignals() {
	QObject::connect(this->ui.filterEdit, &QLineEdit::returnPressed, this, &GUI::filter);
	QObject::connect(this->ui.button, &QPushButton::clicked, this, &GUI::computeTime);
}


void GUI::populateList(std::vector<TimeInterval> elements) {
	this->ui.list->clear();
	for (TimeInterval element : elements) {
		QString item_string = QString::fromStdString(element.toString());
		QListWidgetItem* new_item = new QListWidgetItem{ item_string };
		this->ui.list->addItem(new_item);
	}
}


void GUI::filter() {
	std::string input = this->ui.filterEdit->text().toStdString();
	int max_precipitation = std::stoi(input);
	std::vector<TimeInterval> results = this->repository.filterElements(max_precipitation);
	this->populateList(results);
}


void GUI::computeTime() {
	std::string condition = this->ui.timeEdit->text().toStdString();
	int time = this->repository.getTimeForWeather(condition);
	this->ui.resultEdit->setText(QString::fromStdString(std::to_string(time)));
}