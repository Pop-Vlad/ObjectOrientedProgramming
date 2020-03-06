#include "Gui.h"



Test2::Test2(const Repository& init_repository, QWidget *parent) : repository(init_repository), QMainWindow(parent) {
	ui.setupUi(this);
	this->init();
	this->connectSignals();
	this->populateList(this->repository.getElements());
}


void Test2::init() {

}


void Test2::connectSignals() {
	QObject::connect(this->ui.button, &QPushButton::clicked, this, &Test2::filter);
}


void Test2::populateList(std::vector<Task> elements) {
	this->ui.list->clear();
	for (Task current : elements) {
		QString task_str = QString::fromStdString(current.toString());
		QListWidgetItem* new_item = new QListWidgetItem{ task_str };
		if (current.priority == 1)
			new_item->setBackgroundColor("red");
		this->ui.list->addItem(new_item);
	}
}


void Test2::filter() {
	std::string priority = this->ui.priorityEdit->text().toStdString();
	std::vector<Task> filtered;
	if(priority == "")
		filtered = this->repository.getElementsWithPriority(0);
	else
		filtered = this->repository.getElementsWithPriority(std::stoi(priority));
	this->populateList(filtered);
}