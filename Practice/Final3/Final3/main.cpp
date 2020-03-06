#include "GUI.h"
#include "StatisticsGUI.h"
#include <QtWidgets/QApplication>

#include "Subject.h"

int main(int argc, char *argv[]) {
	Repository* repository = new Repository{ "Programmers.txt", "Files.txt" };
	Controller* controller = new Controller{ repository };
	QApplication a(argc, argv);

	for (Programmer current : controller->getProgrammers()) {
		GUI* w = new GUI{ current.getName(), controller };
		controller->registerObserver(w);
		w->show();
	}
	StatisticsGUI s{};
	s.show();

	return a.exec();
}
