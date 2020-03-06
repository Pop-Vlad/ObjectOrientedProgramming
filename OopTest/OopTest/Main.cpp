#include "Console.h"



int main() {
	Tile* start_position = new Tile;
	std::cout << "Give the start coordinates:\n";
	std::cin >> start_position->x_position;
	std::cin >> start_position->y_position;
	Repository* repository = new Repository();
	Controller* controller = new Controller(repository, start_position);
	Console* console = new Console(controller);
	console->run();
	return 0;
}