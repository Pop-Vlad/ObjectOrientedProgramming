#include "Console.h"



Console::Console(Controller* controller) {
	this->controller = controller;
}


Console::~Console() {
	
}


void Console::run() {
	char command[20];
	char parameters[5][20];
	while (true) {
		try {
			this->readCommand(command, parameters);
			if (strcmp(command, "mode") == 0) {
				if (this->controller->changeMode(parameters[0])) {
					cout << "Mode successfully updated\n\n";
				}
				else {
					cout << "Cannot change mode\n\n";
				}
			}
			else if (strcmp(command, "add") == 0) {
				if (this->controller->add(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4])) {
					cout << "Fragment successfully added\n\n";
				}
				else {
					cout << "Cannot add fragment\n\n";
				}
			}
			else if (strcmp(command, "update") == 0) {
				if (this->controller->update(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4])) {
					cout << "Fragment successfully updated\n\n";
				}
				else {
					cout << "Cannot update fragment\n\n";
				}
			}
			else if (strcmp(command, "delete") == 0) {
				if (this->controller->remove(parameters[0])) {
					cout << "Fragment successfully deleted\n\n";
				}
				else {
					cout << "Cannot delete fragment\n\n";
				}
			}
			else if (strcmp(command, "list") == 0) {
				char buffer[1000];
				if (this->controller->getMode() == 'A') {
					this->controller->listAll(buffer);
					cout << buffer << "\n";
				}
				else {
					this->controller->listSize(buffer, parameters[0], parameters[1]);
					cout << buffer << "\n";
				}
			}
			else if (strcmp(command, "exit") == 0) {
				return;
			}
			else if (strcmp(command, "next") == 0) {
				char buffer[100];
				this->controller->nextFragment(buffer);
				cout << buffer << "\n";
			}
			else if (strcmp(command, "save") == 0) {
				if (this->controller->saveFragment(parameters[0])) {
					cout << "Fragment successfully added\n\n";
				}
				else {
					cout << "Cannot add fragment\n\n";
				}
			}
			else if (strcmp(command, "mylist") == 0) {
				char buffer[1000];
				this->controller->showUserList(buffer);
				cout << buffer << "\n";
			}
			else {
				cout << "Unrecognised command!\n\n";
			}
		}
		catch (PermisiisionError&) {
			cout << "You do not have permissions for this operation\n\n";
		}
		catch (SynataxError&) {
			cout << "What?\n\n";
		}
		catch (exception&) {
			cout << "A bizarre error occured\n\n";
		}
	}
}


void Console::readCommand(char command[20], char parameters[5][20]) {
	const char delimiters[] = " ,";
	char keyboard_input[120];
	char* current_word;
	
	cout << ">>>";
	gets_s(keyboard_input);
	if (strcmp(keyboard_input, "\0") == 0) {
		throw std::exception();
	}
	current_word = strtok(keyboard_input, delimiters);
	strcpy(command, current_word);

	for (int i = 0; i < 5; i++) {
		current_word = strtok(NULL, delimiters);
		if (current_word == NULL) {
			strcpy(parameters[i], "\0");
		}
		else {
			strcpy(parameters[i], current_word);
		}
	}
}