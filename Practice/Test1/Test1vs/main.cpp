#include "Test1vs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repository{ "data.txt" };
	Test1vs w{ repository };
	w.show();
	return a.exec();
}
