#include "GUI.h"



GUI::GUI(const std::string& user_name, const std::string& user_type, IssueRepository* init_repo, QWidget *parent) : repository(init_repo), QMainWindow(parent) {
	ui.setupUi(this);
	this->user = user_name;
	this->setWindowTitle(QString::fromStdString(user_name + " " + user_type));
	this->connectSignals();
	this->populateList();
}

void GUI::populateList() {
	std::vector<Issue> issues = this->repository->getAllIssues();
	std::sort(issues.begin(), issues.end(), [](Issue first, Issue second) {return first.getStatus() + first.getDescription() <
		second.getStatus() + second.getDescription(); });
	this->ui.issuesList->clear();
	for (Issue current : issues) {
		QString content = QString::fromStdString(current.toString());
		QListWidgetItem* new_item = new QListWidgetItem{ content };
		this->ui.issuesList->addItem(new_item);
	}
}

void GUI::connectSignals() {
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &GUI::add);
	QObject::connect(this->ui.removeButton, &QPushButton::clicked, this, &GUI::remove);
	QObject::connect(this->ui.resolveButton, &QPushButton::clicked, this, &GUI::resolve);
	QObject::connect(this->ui.issuesList, &QListWidget::itemSelectionChanged, this, &GUI::selectedItemHandler);
}

void GUI::add() {
	std::string text = this->ui.issueEdit->text().toStdString();
	try {
		this->repository->add(text, this->user);
	}
	catch (std::exception& e) {
		QMessageBox error_box;
		error_box.critical(0, "Error", e.what());
		error_box.setFixedSize(500, 200);
	}
}

void GUI::remove() {
	std::string text = this->ui.issueEdit->text().toStdString();
	try {
		this->repository->remove(text);
	}
	catch (std::exception& e) {
		QMessageBox error_box;
		error_box.critical(0, "Error", e.what());
		error_box.setFixedSize(500, 200);
	}
}

void GUI::resolve() {
	std::string text = this->ui.issueEdit->text().toStdString();
	try {
		this->repository->resolve(text, this->user);
	}
	catch (std::exception& e) {
		QMessageBox error_box;
		error_box.critical(0, "Error", e.what());
		error_box.setFixedSize(500, 200);
	}
}

void GUI::selectedItemHandler() {
	QList<QListWidgetItem*> items = this->ui.issuesList->selectedItems();
	if (items.size() == 0)
		return;
	std::string text = items[0]->text().toStdString();
	std::stringstream stream{ text };
	std::vector<std::string> components;
	std::string current;
	while (std::getline(stream, current, ' '))
		components.push_back(current);
	this->ui.issueEdit->setText(QString::fromStdString(components[0]));
	this->ui.resolveButton->setEnabled(components[1] == "open");
}

void GUI::update() {
	this->populateList();
}