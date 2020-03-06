#include <QtWidgets/QApplication>

#include "GUI.h"



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MemoryRepository* repository = new MemoryRepository{};
	repository->add(AnomalousFragment{ "example1", "ex_size1", 33.1, 12, "ex_photo1" });
	repository->add(AnomalousFragment{ "example2", "ex_size2", 20, 16, "ex_photo2" });
	repository->add(AnomalousFragment{ "example3", "ex_size3", 50, 16, "ex_photo3" });
	repository->add(AnomalousFragment{ "example4", "ex_size4", 11.4, 33, "ex_photo4" });
	repository->add(AnomalousFragment{ "example5", "ex_size5", 94.3, 56, "ex_photo5" });
	repository->add(AnomalousFragment{ "example6", "ex_size6", 76, 23, "ex_photo6" });
	MemoryRepository* user_list = new MemoryRepository{};
	Controller* controller = new Controller{ repository, user_list };
	GUI gui{ controller };
	gui.show();
	return a.exec();
}