#include "Console.h"

void tests();

int main() {
	tests();
	//return 0;
	repository* repository_object = createRepository(1000);
	controller* controller_object = createController(repository_object);
	console* console_object = createConsole(controller_object);
	run(console_object);
	destroyRepository(repository_object);
	destroyController(controller_object);
	destroyConsole(console_object);
	return 0;
}


void tests() {
	repository* repository_object = createRepository(1000);
	controller* controller_object = createController(repository_object);
	console* console_object = createConsole(controller_object);
	addController(controller_object, "10", "luminated", "wood", "34");
	addController(controller_object, "23", "dark", "wood", "56");
	addController(controller_object, "54", "luminated", "steel", "98");
	addController(controller_object, "67", "dim", "wood", "34");
	addController(controller_object, "98", "luminated", "wood", "12");
	addController(controller_object, "33", "dim", "iron", "56");
	addController(controller_object, "44", "luminated", "stone", "78");
	char buffer[1000];
	ListByLuminosityInArea(controller_object, "dim", buffer);
	printf("%s", buffer);
	destroyRepository(repository_object);
	destroyController(controller_object);
	destroyConsole(console_object);
}