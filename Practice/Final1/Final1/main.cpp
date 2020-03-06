#include "GUI.h"
#include <QtWidgets/QApplication>


void testAdd() {
	IssueRepository repository{ "Tusers.txt", "Tissues.txt" };
	repository.add("aaa", "Mary");
	try {
		repository.add("aaa", "Mary");
		assert(false);
	}
	catch (std::exception& e) {
		assert(true);
	}
	try {
		repository.add("bbb", "Charlie");
		assert(false);
	}
	catch (std::exception& e) {
		assert(true);
	}
	try {
		repository.add("", "Mary");
		assert(false);
	}
	catch (std::exception& e) {
		assert(true);
	}
}

void testUpdate() {
	IssueRepository repository{ "Tusers.txt", "Tissues.txt" };
	repository.resolve("aaa", "Charlie");
	try {
		repository.resolve("aaa", "Mary");
		assert(false);
	}
	catch (std::exception& e) {
		assert(true);
	}
	try {
		repository.resolve("aaa", "Charlie");
		assert(false);
	}
	catch (std::exception& e) {
		assert(true);
	}
	try {
		repository.resolve("uwu", "Charlie");
		assert(false);
	}
	catch (std::exception& e) {
		assert(true);
	}
	repository.remove("aaa");
}

int main(int argc, char *argv[]) {
	testAdd();
	testUpdate();
	QApplication a(argc, argv);
	IssueRepository repository{ "users.txt", "issues.txt" };
	for (User current : repository.getAllUsers()) {
		GUI* w = new GUI{ current.getName(), current.getType() , &repository };
		repository.registerObserver(w);
		w->show();
	}
	return a.exec();
}
