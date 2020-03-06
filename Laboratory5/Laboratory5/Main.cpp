#include "Console.h"
#include "Main.h"

using namespace std;



int main() {
	Repository* repository = new Repository();
	Controller* controller = new Controller(repository);
	Console* console = new Console(controller);
	console->run();
	delete repository;
	delete controller;
	delete console;
	return 0;
}