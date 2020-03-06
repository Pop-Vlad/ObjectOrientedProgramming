#include "GUI.h"
#include "PGUI.h"
#include <QtWidgets/QApplication>

#include "Controller.h"
#include <assert.h>

void testAdd() {
	Repository* repo = new Repository{ "PTest.txt", "QTest.txt" };
	Controller contrl{ repo };
	Question q1{ 10, "text", "t", 10 };
	Question q2{ 1, "text", "t", 10 };
	Question q3{ 12, "", "t", 10 };
	contrl.addQuestion(q1);
	try {
		contrl.addQuestion(q2);
	}
	catch (std::exception& e) {
		assert(true);
	}
	try {
		contrl.addQuestion(q3);
	}
	catch (std::exception& e) {
		assert(true);
	}
	assert(contrl.getQuestions().size() == 3);
}

int main(int argc, char *argv[])
{
	testAdd();
	QApplication a(argc, argv);

	Repository repository{ "participants.txt", "questions.txt" };
	Controller controller{ &repository };
	PGUI* presenter = new PGUI{ &controller };
	presenter->show();
	for (Participant p : controller.getParticipants()) {
		GUI* w = new GUI(&controller, p.getName());
		w->show();
		presenter->registerObserver(w);
	}
	return a.exec();
}
