#include "Console.h"
#include "Main.h"

using namespace std;



int main() {
	Repository<AnomalousFragment>* repository = new Repository<AnomalousFragment>();
	Controller* controller = new Controller(repository);
	Console* console = new Console(controller);
	console->run();
	delete repository;
	delete controller;
	delete console;
	return 0;
}