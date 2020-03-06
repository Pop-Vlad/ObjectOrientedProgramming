#include "UI.h"



UI::UI(Controller* input_controller) {
	this->controller = input_controller;
}


void UI::run() {
	while (1) {
		std::vector<std::string> arguments;
		arguments = this->getCommand();
		if (arguments[0] == "add") {
			this->controller->addPainting(arguments[1], arguments[2], stoi(arguments[3]));
		}
		else if (arguments[0] == "listAll") {
			std::vector<Painting> paintings = this->controller->getAll();
			for (auto iterator = paintings.begin(); iterator != paintings.end(); iterator++) {
				auto current = *iterator;
				std::cout << "	Title: " + current.getTitle() << " ,Artist: " << current.getArtist() << " ,Year: " << current.getYear() << "\n";
			}
		}
		else if (arguments[0] == "move") {
			this->controller->movePainting(arguments[1], arguments[2], stoi(arguments[3]));
		}
		else if (arguments[0] == "listSpecial") {
			std::vector<Painting> paintings = this->controller->getAllSpecialStorage();
			for (auto iterator = paintings.begin(); iterator != paintings.end(); iterator++) {
				auto current = *iterator;
				std::cout << "	Title: " + current.getTitle() << " ,Artist: " << current.getArtist() << " ,Year: " << current.getYear() << "\n";
			}
		}
		else if (arguments[0] == "undo") {
			this->controller->undo();
		}
		else if (arguments[0] == "exit") {
			return;
		}
		else {
			std::cout << "	Unrecognized command\n";
		}
	}
}


std::vector<std::string> UI::getCommand() {
	std::string input;
	std::cout << ">>>";
	std::getline(std::cin, input);
	std::stringstream command{ input };
	std::string current;
	std::vector<std::string> arguments;
	while (std::getline(command, current, ' ')) {
		arguments.push_back(current);
	}
	return arguments;
}