#include "Console.h"

#define reset_colour "\033[0m"
#define menu_colour "\033[33;40m";
#define output_colour "\033[32;40m"
#define command_colour "\033[96;40m"
#define error_colour "\033[31;40m"

void Console::run() {
	std::vector<std::string> arguments;
	Validator validator;
	while (true) {
		try {
			this->printMenu();
			arguments = this->readCommand();
			system("cls");
			if (!validator.validateInput(arguments)) {
				throw ValidationError{ "Invalid input" };
			}
			std::cout << output_colour;
			if (arguments.front() == "mode") {
				this->controller->setMode(arguments[1][0]);
				std::cout << "Mode successfully updated\n\n";
			}
			else if (arguments.front() == "add") {
				this->controller->add(AnomalousFragment{ arguments[1], arguments[2], std::stod(arguments[3]), std::stoi(arguments[4]),
					arguments[5] });
				std::cout << "Fragment successfully added\n\n";
			}
			else if (arguments.front() == "update") {
				this->controller->update(AnomalousFragment{ arguments[1], arguments[2], std::stod(arguments[3]), std::stoi(arguments[4]),
					arguments[5] });
				std::cout << "Fragment successfully updated\n\n";
			}
			else if (arguments.front() == "delete") {
				this->controller->remove(arguments[1]);
				std::cout << "Fragment successfully deleted\n\n";
			}
			else if (arguments.front() == "list") {
				if (arguments.size() == 1) {
					std::vector<AnomalousFragment> fragments = this->controller->listAll();
					for (std::vector<AnomalousFragment>::iterator iterator = fragments.begin(); iterator != fragments.end(); iterator++) {
						std::cout << *iterator << "\n";
					}
					std::cout << "\n";
				}
				else {
					std::vector<AnomalousFragment> fragments = this->controller->listFiltered(arguments[1], std::stoi(arguments[2]));
					for (std::vector<AnomalousFragment>::iterator iterator = fragments.begin(); iterator != fragments.end(); iterator++) {
						std::cout << *iterator << "\n";
					}
					std::cout << "\n";
				}
			}
			else if (arguments.front() == "exit") {
				std::cout << reset_colour;
				return;
			}
			else if (arguments.front() == "next") {
				std::cout << this->controller->nextFragment() << "\n\n";
			}
			else if (arguments.front() == "save") {
				this->controller->saveFragment(arguments[1]);
				std::cout << "Fragment successfully added\n\n";
			}

			
			else if (arguments.front() == "mylist") {
				std::vector<AnomalousFragment> fragments = this->controller->showUserList();
				for (std::vector<AnomalousFragment>::iterator iterator = fragments.begin(); iterator != fragments.end(); iterator++) {
					std::cout << *iterator << "\n";
				}
			}
			else if (arguments.front() == "fileLocation") {
				std::string file_path{};
				for (int i = 1; i < arguments.size(); i++) {
					file_path += arguments[i] + " ";
				}
				this->controller->changeFile(file_path);
				std::cout << "File location set\n\n";
			}
			else {
				std::cout << error_colour;
				std::cout << "Unrecognised command!\n\n";
			}
			std::cout << reset_colour;
		}
		catch (GenericException& some_exception) {
			std::cout << error_colour;
			std::cout << some_exception.what() << "\n\n";
			std::cout << reset_colour;
		}
		catch (...) {
			std::cout << error_colour;
			std::cout << "An error occured\n\n";
			std::cout << reset_colour;
		}
	}
}


std::vector<std::string> Console::readCommand() const {
	char keyboard_input[120];
	std::cout << command_colour;
	std::cout << ">>>";
	gets_s(keyboard_input);
	std::cout << reset_colour;
	if (strcmp(keyboard_input, "\0") == 0) {
		return std::vector<std::string>{};
	}
	const char delimiters[] = " ,";
	char* current_word;
	std::vector<std::string> parameters;
	current_word = strtok(keyboard_input, delimiters);
	while (current_word != NULL) {
		parameters.push_back(std::string{ current_word });
		current_word = strtok(NULL, delimiters);
	}
	return parameters;
}


void Console::printMenu() const {
	std::cout << menu_colour;
	std::cout << "mode <new mode> - change the mode to gain permissions.\n";
	std::cout << "fileLocation <new location> - change the file in which the fragments are stored\n";
	std::cout << "For mode A:\n";
	std::cout << "	add <id> <size> <infection> <microfragments> <photograph> - add a new fragment\n";
	std::cout << "	update <id> <new size> <new infection> <new microfragments> <new photograph> - update the data of a fragment\n";
	std::cout << "	delete <id> - delete a fragment\n";
	std::cout << "	list - list all the fragments\n";
	std::cout << "For mode B:\n";
	std::cout << "	next - see the data of the next fragment\n";
	std::cout << "	save <id> - save a fragment in your list\n";
	std::cout << "	list <size> <quantity of microfragments> - search for fragments with the given conditions\n";
	std::cout << "	mylist - show saved fragments\n";
	std::cout << "exit - exit the program\n\n";
	std::cout << reset_colour;
}