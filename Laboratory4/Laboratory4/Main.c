#include <crtdbg.h>
#include "Console.h"

int main() {
	repository* repository_object = createRepository();
	controller* controller_object = createController(repository_object);
	console* console_object = createConsole(controller_object);
	run(console_object);
	destroyRepository(repository_object);
	destroyController(controller_object);
	destroyConsole(console_object);
	_CrtDumpMemoryLeaks();
	return 0;
}