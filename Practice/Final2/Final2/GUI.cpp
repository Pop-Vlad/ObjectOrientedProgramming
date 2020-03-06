#include "GUI.h"

GUI::GUI(Controller* controller, std::string user, QWidget *parent) : controller(controller), user(user), QMainWindow(parent) {
	ui.setupUi(this);
	this->score = 0;
	this->setWindowTitle(QString::fromStdString(this->user));
	this->populateList();
	this->ui.QuestionsList->setSelectionMode(this->ui.QuestionsList->SingleSelection);
	this->connectSignals();
}

void GUI::answer() {
	auto items = this->ui.QuestionsList->selectedItems();
	if (items.size() == 0)
		return;
	std::string content = items.first()->text().toStdString();
	std::stringstream stream{ content };
	std::vector<std::string> components;
	std::string current;
	while (std::getline(stream, current, ' '))
		components.push_back(current);
	std::string answer = this->ui.answerEdit->text().toStdString();
	Question selectedQuestion{ std::stoi(components[0]), components[1], answer, std::stoi(components[2]) };
	this->answered.push_back(selectedQuestion.getId());
	for (auto q : this->controller->getQuestions()) {
		if (q.getId() == selectedQuestion.getId())
			if (q.getCorrectAnswer() == answer)
				this->score += selectedQuestion.getScore();
	}
	this->populateList();
}

void GUI::connectSignals() {
	QObject::connect(this->ui.answerButton, &QPushButton::clicked, this, &GUI::answer);
	QObject::connect(this->ui.QuestionsList, &QListWidget::itemSelectionChanged, this, &GUI::updateSelected);
}

void GUI::updateSelected() {
	auto items = this->ui.QuestionsList->selectedItems();
	if (items.size() == 0)
		return;
	std::string content = items.first()->text().toStdString();
	std::stringstream stream{ content };
	std::vector<std::string> components;
	std::string current;
	while (std::getline(stream, current, ' '))
		components.push_back(current);
	for (int id : this->answered)
		if (id == std::stoi(components[0])) {
			this->ui.answerButton->setEnabled(false);
			return;
		}
	this->ui.answerButton->setEnabled(true);
}

void GUI::populateList() {
	std::vector<Question> questions = this->controller->getQuestions();
	std::sort(questions.begin(), questions.end(), [](Question first, Question second) {return first.getScore() > second.getScore(); });
	this->ui.QuestionsList->clear();
	for (Question q : questions) {
		QListWidgetItem* new_item = new QListWidgetItem{ QString::fromStdString(q.toStringParticipant()) };
		for(int id : this->answered)
			if (id == q.getId()) {
				new_item->setBackgroundColor("green");
				break;
			}
		this->ui.QuestionsList->addItem(new_item);
	}
	this->ui.score->setText(QString::fromStdString(std::to_string(this->score)));
}

void GUI::update() {
	this->populateList();
}