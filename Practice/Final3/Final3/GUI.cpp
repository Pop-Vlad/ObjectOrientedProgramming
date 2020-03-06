#include "GUI.h"

GUI::GUI(std::string user, Controller* controller, QWidget *parent) : user(user), controller(controller), QMainWindow(parent) {
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(this->user));
	this->updateUI();
	this->connectSignals();
}

void GUI::connectSignals() {
	QObject::connect(this->ui.sourcesList, &QListWidget::itemSelectionChanged, this, &GUI::reviewButtonUpdate);
	QObject::connect(this->ui.reviseButton, &QPushButton::clicked, this, &GUI::revise);
}

void GUI::updateUI() {
	this->updateList();
	this->scoreUpdate();
	this->reviewButtonUpdate();
}

void GUI::updateList() {
	this->ui.sourcesList->clear();
	std::vector<SourceFile> files = this->controller->getFiles();
	std::sort(files.begin(), files.end(), [](SourceFile first, SourceFile second) {return first.getName() < second.getName(); });
	for (auto file : files) {
		QListWidgetItem* new_item = new QListWidgetItem{ QString::fromStdString(file.toString()) };
		if (file.getStatus() == "revised") {
			this->ui.reviseButton->setEnabled(false);
			new_item->setBackgroundColor("green");
		}
		else {
			this->ui.reviseButton->setEnabled(true);
			QFont font;
			font.setBold(true);
			new_item->setFont(font);
		}
		if (file.getCreator() == this->user)
			this->ui.reviseButton->setEnabled(false);
		this->ui.sourcesList->addItem(new_item);
	}
}

void GUI::scoreUpdate() {
	std::string revised = "Revised: " + std::to_string(this->controller->getRevised(this->user));
	std::string remaining = "Remaining: " + std::to_string(this->controller->getRemainig(this->user));
	this->ui.revisedLabel->setText(QString::fromStdString(revised));
	this->ui.remainingLabel->setText(QString::fromStdString(remaining));
	if (remaining == "Remaining: 0") {
		QMessageBox box;
		box.information(0, "Finished", "Congratulations");
		box.setFixedSize(200, 500);
	}
}

void GUI::reviewButtonUpdate() {
	auto selected_items = this->ui.sourcesList->selectedItems();
	if (selected_items.size() != 0) {
		std::string text = selected_items[0]->text().toStdString();
		std::stringstream sstream{ text };
		std::vector<std::string> components;
		std::string current;
		while (std::getline(sstream, current, ' '))
			components.push_back(current);
		if (components[1] == "revised")
			this->ui.reviseButton->setEnabled(false);
		else if (components[2] == this->user)
			this->ui.reviseButton->setEnabled(false);
		else
			this->ui.reviseButton->setEnabled(true);
	}
	else
		this->ui.reviseButton->setEnabled(false);
}

void GUI::revise() {
	std::string file;
	auto selected_items = this->ui.sourcesList->selectedItems();
	if (selected_items.size() != 0) {
		std::string text = selected_items[0]->text().toStdString();
		std::stringstream sstream{ text };
		std::vector<std::string> components;
		std::string current;
		while (std::getline(sstream, current, ' '))
			components.push_back(current);
		file = components[0];
	}
	else
		return;
	this->controller->revise(file, this->user);
}


void GUI::update() {
	this->updateUI();
}