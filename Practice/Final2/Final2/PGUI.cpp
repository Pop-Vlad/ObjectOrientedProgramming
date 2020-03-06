#include "PGUI.h"

PGUI::PGUI(Controller* controller, QWidget *parent) : controller(controller), user(user), QMainWindow(parent) {
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString("Presenter"));
	this->connectSignals();
	this->populateList();
}

void PGUI::connectSignals() {
	QObject::connect(this->ui.addButton, &QPushButton::clicked, this, &PGUI::addQuestion);
}

void PGUI::addQuestion() {
	int id = std::stoi(this->ui.idEdit->text().toStdString());
	std::string text = this->ui.textEdit->text().toStdString();
	std::string answer = this->ui.answerEdit->text().toStdString();
	int score = std::stoi(this->ui.scoreEdit->text().toStdString());
	Question new_question{ id, text, answer, score };
	try {
		this->controller->addQuestion(new_question);
	}
	catch (std::exception& e) {
		QMessageBox error{};
		error.critical(0, "Error", e.what());
	}
	this->populateList();
	this->notify();
}


void PGUI::populateList() {
	std::vector<Question> questions = this->controller->getQuestions();
	std::sort(questions.begin(), questions.end(), [](Question first, Question second) {return first.getId() < second.getId(); });
	this->ui.QuestionsList->clear();
	for (Question q : questions) {
		QListWidgetItem* new_item = new QListWidgetItem{ QString::fromStdString(q.toString()) };
		this->ui.QuestionsList->addItem(new_item);
	}
}