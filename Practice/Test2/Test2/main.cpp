#include "Gui.h"
#include <QtWidgets/QApplication>

#include "Tests.cpp"



int main(int argc, char *argv[]) {
	Test::testFilter();
	QApplication a(argc, argv);
	Repository repository{ "data.txt" };
	Test2 w{ repository };
	w.show();
	return a.exec();
}
