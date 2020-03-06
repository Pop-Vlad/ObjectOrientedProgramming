#include "GUI.h"
#include <QtWidgets/QApplication>

#include <assert.h>



void testBestMatch() {
	Repository repository{ "test.txt" };
	assert(repository.bestMatch("ab").toString() == "abc a1");
	assert(repository.bestMatch("de").toString() == "cde c1");
	assert(repository.bestMatch("nn").toString() == "mnnp m2");
}

int main(int argc, char *argv[])
{
	testBestMatch();
	QApplication a(argc, argv);
	Repository repository{ "data.txt" };
	GUI w{ repository };
	w.show();
	return a.exec();
}
