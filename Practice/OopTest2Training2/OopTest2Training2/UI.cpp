#include "UI.h"



void UI::run() {
	while (1) {
		std::vector<std::string> arguments = this->getCommand();
		if (arguments[0] == "add") {
			this->controller.addCar(arguments[1], arguments[2], std::stoi(arguments[3]));
		}
		else if (arguments[0] == "list") {
			std::vector<Pod> pods = this->controller.getAllCars();
			for (auto iterator = pods.begin(); iterator != pods.end(); iterator++) {
				auto current_pod = *iterator;
				std::cout << current_pod.toString() << "\n";
			}
		}
		else if (arguments[0] == "exit") {
			return;
		}
		else {
			std::cout << "Unrecognised command\n";
		}
	}
}


std::vector<std::string> UI::getCommand() {
	std::string input;
	std::cout << ">>>";
	std::getline(std::cin, input);
	std::stringstream command{ input };
	std::string current_word;
	std::vector<std::string> arguments;
	while (std::getline(command, current_word, ' ')) {
		arguments.push_back(current_word);
	}
	return arguments;
}