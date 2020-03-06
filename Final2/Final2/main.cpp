#include "GUI.h"
#include <QtWidgets/QApplication>
#include <assert.h>

void testAdd() {
	Repository* repository = new Repository{ "testWriters.txt", "testIdeas.txt" };
	Idea new_idea1{ "description", "proposed", "Vlad", 2 };
	Idea new_idea2{ "description", "proposed", "Vlad", 3 };
	repository->addIdea(new_idea1);
	repository->addIdea(new_idea2);
	try {
		repository->addIdea(new_idea1);
		assert(false);
	}
	catch (std::exception& e) {
		assert(true);
	}
	assert(repository->getIdeas().size() == 7);
}

void testUpdateStatus() {
	Repository* repository = new Repository{ "testWriters.txt", "testIdeas.txt" };
	Idea new_idea1{ "aaa", "proposed", "Adam", 1 };
	repository->updateStatus(new_idea1, "accepted");
	auto ideas = repository->getIdeas();
	assert(ideas.size() == 5);
	auto it = std::find_if(ideas.begin(), ideas.end(), [](Idea check) {return check.getAct() == 1 && check.getCreator() == "Adam" &&
		check.getDescription() == "aaa" && check.getStatus() == "accepted"; });
	assert(it != ideas.end());
}


int main(int argc, char *argv[])
{
	testAdd();
	testUpdateStatus();
	Repository* repository = new Repository{ "writers.txt", "ideas.txt" };
	Controller* controller = new Controller{ repository };
	QApplication a(argc, argv);
	for (auto writer : controller->getWriters()) {
		GUI* w = new GUI{ writer.getName(), controller };
		controller->registerObserver(w);
		w->show();
	}
	return a.exec();
}
