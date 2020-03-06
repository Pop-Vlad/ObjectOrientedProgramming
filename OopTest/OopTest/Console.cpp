#include "Console.h"



Console::Console(Controller* controller) {
	this->controller = controller;
}


void Console::run() {
	char command[20], parameter[20];
	while (1) {
		try {
			this->readCommand(command, parameter);
			if (strcmp(command, "move") == 0) {
				Tile* new_postion = this->controller->moveBot(parameter[0]);
				std::cout << "New position: " << new_postion->x_position << "-" << new_postion->y_position << "\n";
			}
			else if (strcmp(command, "list") == 0) {
				std::vector<Tile*> tiles = this->controller->getCleanedTiles();
				for (int i = 0; i < tiles.size(); i++) {
					Tile* current_tile = tiles.at(i);
					std::cout << current_tile->x_position << "-" << current_tile->y_position << "\n";
				}
				std::cout << this->controller->getCleanedTiles().size() << "%100\n";
			}
			else if (strcmp(command, "exit") == 0) {
				break;
			}
			else {
				std::cout << "Unrecognised command\n";
			}
		}
		catch (MoveError&) {
			std::cout << "Cannot move at given position\n";
		}
		catch (std::exception&) {
			std::cout << "An error occured\n";
		}
	}
}


void Console::readCommand(char* command, char* parameter) {
	char keyboard_input[40];
	std::cin >> keyboard_input;
	char* token;
	token = strtok(keyboard_input, "-");
	strcpy(command, token);
	token = strtok(NULL, "-");
	if (token != NULL) {
		strcpy(parameter, token);
	}
	else {
		strcpy(parameter, "\0");
	}
}