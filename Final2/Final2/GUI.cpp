#include "GUI.h"

GUI::GUI(std::string init_user, Controller* init_contrloller, QWidget *parent)	: QMainWindow(parent), user(init_user), controller(init_contrloller) {
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->user));
	this->connectSignals();
	this->update();
}

void GUI::populateList() {
	this->ui.ideasList->clear();
	std::vector<Idea> ideas = this->controller->getIdeas();
	std::sort(ideas.begin(), ideas.end(), [](Idea first, Idea second) {return first.getAct() < second.getAct(); });
	for (auto idea : ideas) {
		QListWidgetItem* new_item = new QListWidgetItem{ QString::fromStdString(idea.toString()) };
		this->ui.ideasList->addItem(new_item);
	}
}

void GUI::connectSignals() {
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &GUI::addIdea);
	QObject::connect(this->ui.saveButton, &QPushButton::clicked, this, &GUI::savePlot);
	QObject::connect(this->ui.developButton, &QPushButton::clicked, this, &GUI::develop);
	QObject::connect(this->ui.reviseButton, &QPushButton::clicked, this, &GUI::revise);
	QObject::connect(this->ui.ideasList, &QListWidget::itemSelectionChanged, this, &GUI::updateReviseButton);
}

void GUI::addIdea() {
	std::string description = this->ui.descriptionEdit->text().toStdString();
	std::string act = this->ui.actEdit->text().toStdString();
	try {
		if (description == "")
			throw std::exception{ "No description" };
		if (act != "1" && act != "2" && act != "3")
			throw std::exception{ "Invalid act" };
		this->controller->addIdea(this->user, description, std::stoi(act));
	}
	catch (std::exception& e) {
		QMessageBox m;
		m.critical(0, "Error", e.what());
		m.setFixedSize(200, 500);
	}
}

void GUI::update() {
	this->populateList();
	this->updateDevelopButton();
	this->updateReviseButton();
}

void GUI::savePlot() {
	this->controller->savePlot("SaveFile - " + this->user + ".txt");
}

void GUI::develop() {
	std::vector<Idea> allIdeas = this->controller->getIdeas();
	std::vector<Idea> filtered;
	std::string writer = this->user;
	auto it = std::copy_if(allIdeas.begin(), allIdeas.end(), std::back_inserter(filtered),
		[writer](Idea current) {return current.getCreator() == writer && current.getStatus() == "accepted"; });
	for (auto item : filtered) {
		std::string content = item.toString();
		DevelopGUI* w = new DevelopGUI{ content };
		w->show();
	}
}

void GUI::updateDevelopButton() {
	std::vector<Idea> allIdeas = this->controller->getIdeas();
	std::vector<Idea> filtered;
	std::string writer = this->user;
	auto it = std::copy_if(allIdeas.begin(), allIdeas.end(), std::back_inserter(filtered),
		[writer](Idea current) {return current.getCreator() == writer && current.getStatus() == "accepted"; });
	if (filtered.size() == 0) {
		this->ui.developButton->setEnabled(false);
	}
	else
		this->ui.developButton->setEnabled(true);
}

void GUI::revise() {
	auto selectedItems = this->ui.ideasList->selectedItems();
	if (selectedItems.size() == 0)
		return;
	QListWidgetItem* item = selectedItems.first();
	std::string content = item->text().toStdString();
	std::stringstream sstream{ content };
	std::string current;
	std::vector<std::string> components;
	while (std::getline(sstream, current, ' '))
		components.push_back(current);
	Idea to_revise{ components[0], components[1], components[2], std::stoi(components[3]) };
	this->controller->revise(to_revise);
}

void GUI::updateReviseButton() {
	if (!this->controller->isSenior(this->user)) {
		this->ui.reviseButton->setEnabled(false);
		return;
	}
	auto selectedItems = this->ui.ideasList->selectedItems();
	if (selectedItems.size() == 0) {
		this->ui.reviseButton->setEnabled(false);
		return;
	}
	QListWidgetItem* item = selectedItems.first();
	std::string content = item->text().toStdString();
	std::stringstream sstream{ content };
	std::string current;
	std::vector<std::string> components;
	while (std::getline(sstream, current, ' '))
		components.push_back(current);
	Idea to_revise{ components[0], components[1], components[2], std::stoi(components[3]) };
	if (to_revise.getStatus() == "accepted")
		this->ui.reviseButton->setEnabled(false);
	else
		this->ui.reviseButton->setEnabled(true);
}