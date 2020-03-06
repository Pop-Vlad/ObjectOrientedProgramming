#include "Console.h"

#include "Test.h"



int main() {
	//Test::testAll();
	SqlRepository* repository = new SqlRepository{};
	MemoryRepository* user_list = new MemoryRepository{};
	Controller controller{ repository, user_list };
	Console console{ &controller };
	console.run();
	return 0;
}