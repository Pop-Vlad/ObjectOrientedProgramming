#include "GUI.h"
#include <QtWidgets/QApplication>
#include "Test.cpp"
#include <assert.h>



void testComputeHours() {
	Repository repository{ "test.txt" };
	assert(repository.getTimeForWeather("a") == 4);
	assert(repository.getTimeForWeather("b") == 5);
	assert(repository.getTimeForWeather("c") == 13);
	assert(repository.getTimeForWeather("d") == 0);
	assert(repository.getTimeForWeather("") == 0);
}


int main(int argc, char *argv[]) {
	testComputeHours();
	QApplication a(argc, argv);
	Repository repository{ "data.txt" };
	GUI w{ repository };
	w.show();
	return a.exec();
}