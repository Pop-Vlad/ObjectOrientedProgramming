#include "Test1vs.h"



Test1vs::Test1vs(Repository init_repository, QWidget *parent) : repository(init_repository), QMainWindow(parent) {
	ui.setupUi(this);
	this->init();
	this->connectSignals();
	this->polupateList();
}


void Test1vs::init() {

}


void Test1vs::connectSignals() {
	QObject::connect(this->ui.button, &QPushButton::clicked, this, &Test1vs::buttonHandler);
}


void Test1vs::buttonHandler() {
	std::string manufacturer = this->ui.input->text().toStdString();
	int count = this->repository.getCarCount(manufacturer);
	this->ui.result->setText(QString::fromStdString(std::to_string(count)));
}


void Test1vs::polupateList() {
	this->ui.list->clear();
	std::vector<Car> cars = this->repository.getElements();
	for (Car current : cars) {
		QString car_str = QString::fromStdString(current.toString());
		QListWidgetItem* item = new QListWidgetItem{ car_str };
		item->setTextColor(current.colour.c_str());
		this->ui.list->addItem(item);
		this->ui.list->sortItems();
	}
}