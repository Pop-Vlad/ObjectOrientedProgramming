#include <crtdbg.h>
#include <assert.h>
#include "Console.h"

void tests1();

void tests2();

int main() {
	tests1();
	tests2();
	return 0;
	repository* repository_object = createRepository();
	controller* controller_object = createController(repository_object);
	console* console_object = createConsole(controller_object);
	run(console_object);
	destroyController(controller_object);
	destroyConsole(console_object);
	_CrtDumpMemoryLeaks();
	return 0;
}


void tests1() {
	repository* repository_object = createRepository(1000);
	controller* controller_object = createController(repository_object);
	console* console_object = createConsole(controller_object);
	printf("Tests bonus 1: \n\n");
	addController(controller_object, "10", "black", "wood", "34");
	addController(controller_object, "23", "dark", "wood", "56");
	addController(controller_object, "54", "gloomy", "steel", "98");
	addController(controller_object, "67", "dim", "wood", "34");
	addController(controller_object, "98", "obscure", "wood", "12");
	addController(controller_object, "33", "tenebrous", "iron", "56");
	addController(controller_object, "44", "unlit", "stone", "78");
	char buffer[1000];
	listSturdinessAscending(controller_object, "100", buffer);
	printf("%s\n", buffer);

	listSturdinessDescending(controller_object, "100", buffer);
	printf("%s\n", buffer);

	destroyRepository(repository_object);
	destroyController(controller_object);
	destroyConsole(console_object);
}

void tests2() {
	repository* repository_object = createRepository();
	controller* controller_object = createController(repository_object);
	console* console_object = createConsole(controller_object);

	printf("Tests bonus 2: \n\n");

	//test add
	addController(controller_object, "10", "black", "wood", "34");
	addController(controller_object, "23", "dark", "wood", "56");
	addController(controller_object, "54", "gloomy", "steel", "98");
	addController(controller_object, "67", "dim", "wood", "34");
	addController(controller_object, "98", "obscure", "wood", "12");
	addController(controller_object, "33", "tenebrous", "iron", "56");
	addController(controller_object, "44", "unlit", "stone", "78");
	assert(repository_object->size == 7);
	assert(((barricade*)repository_object->elements[2])->location_code == 54);
	assert(((barricade*)repository_object->elements[0])->barricade_sturdiness == 34);
	assert(((barricade*)repository_object->elements[6])->location_code == 44);

	//test delete
	deleteController(controller_object, "23");
	deleteController(controller_object, "44");
	deleteController(controller_object, "98");
	assert(repository_object->size == 4);
	assert(((barricade*)repository_object->elements[0])->barricade_sturdiness == 34);

	// test update
	updateController(controller_object, "10", "dim", "iron", "100");
	updateController(controller_object, "54", "aaa", "bbb", "22");
	assert(((barricade*)repository_object->elements[0])->barricade_sturdiness == 100);
	assert(((barricade*)repository_object->elements[0])->location_code == 10);
	assert(((barricade*)repository_object->elements[2])->barricade_sturdiness == 22);
	assert(((barricade*)repository_object->elements[2])->location_code == 54);

	printf("All tests passed \n\n");

	destroyController(controller_object);
	destroyConsole(console_object);
}