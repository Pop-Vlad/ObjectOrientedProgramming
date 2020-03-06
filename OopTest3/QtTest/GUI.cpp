#include "GUI.h"

GUI::GUI(Repository& init_repository, QWidget *parent) : repository(init_repository), QMainWindow(parent) {
	ui.setupUi(this);
	this->connectSignals();
	this->populateList(this->repository.getElements());
}


void GUI::connectSignals() {
	QObject::connect(this->ui.searchEdit, &QLineEdit::textChanged, this, &GUI::search);
	QObject::connect(this->ui.button, &QPushButton::clicked, this, &GUI::getBestMatch);
}


void GUI::populateList(std::vector<Document> documents) {
	this->ui.mainList->clear();
	for (Document current : documents) {
		QString current_string = QString::fromStdString(current.toString());
		QListWidgetItem* new_item = new QListWidgetItem{ current_string };
		this->ui.mainList->addItem(new_item);
	}
}


void GUI::search() {
	std::string text = this->ui.searchEdit->text().toStdString();
	std::vector<Document> results = this->repository.search(text);
	this->populateList(results);
}


void GUI::getBestMatch() {
	std::string text = this->ui.searchEdit->text().toStdString();
	Document best_match = this->repository.bestMatch(text);
	this->ui.matchEdit->setText(QString::fromStdString(best_match.toString()));
}