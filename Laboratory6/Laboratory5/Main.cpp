#include "Console.h"

using namespace std;



int main() {
	Repository* repository = new Repository;
	Controller* controller = new Controller(repository);
	Console* console = new Console(controller);
	console->run();
	delete controller;
	delete console;
	return 0;
}