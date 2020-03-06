#include "Console.h"

#include "Test.h"



int main() {
	Test::testAll();
	/*FileRepository repository{};
	Controller controller{ &repository };
	Console console{ &controller };
	console.run();*/
	return 0;
}