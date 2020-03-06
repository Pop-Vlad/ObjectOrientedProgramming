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
				AnomalousFragment* new_fragment = this->createFragment(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4]);
				if (this->controller->add(new_fragment)) {
					cout << "Fragment successfully added\n\n";
				}
				else {
					cout << "Cannot add fragment\n\n";
				}
			}
			else if (strcmp(command, "update") == 0) {
				AnomalousFragment* new_fragment = this->createFragment(parameters[0], parameters[1], parameters[2], parameters[3], parameters[4]);
				if (this->controller->update(new_fragment)) {
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
				if (this->controller->getMode() == 'A') {
					AnomalousFragment* list_of_fragments[100];
					int size;
					char buffer[1000];
					this->controller->listAll(list_of_fragments, size);
					char current_fragment_string[100];
					strcpy(buffer, "");
					for (int i = 0; i < size; i++) {
						AnomalousFragment* current_fragment = list_of_fragments[i];
						current_fragment->toString(current_fragment_string);
						strcat(buffer, current_fragment_string);
					}
					cout << buffer << "\n";
				}
				else {
					AnomalousFragment* fragment_to_compare = createFragment((char*)"id", parameters[0], (char*)"infection", parameters[1], (char*)"photograph");
					AnomalousFragment* list_of_fragments[100];
					int size;
					char buffer[1000];
					this->controller->listSize(list_of_fragments, size, fragment_to_compare);
					char current_fragment_string[100];
					strcpy(buffer, "");
					for (int i = 0; i < size; i++) {
						AnomalousFragment* current_fragment = list_of_fragments[i];
						current_fragment->toString(current_fragment_string);
						strcat(buffer, current_fragment_string);
					}
					cout << buffer << "\n";
				}
			}
			else if (strcmp(command, "exit") == 0) {
				return;
			}
			else if (strcmp(command, "next") == 0) {
				char buffer[100];
				AnomalousFragment* current_fragment = this->controller->nextFragment();
				current_fragment->toString(buffer);
				cout << buffer << "\n\n";
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
				AnomalousFragment* list_of_fragments[100];
				int size;
				char buffer[1000];
				this->controller->showUserList(list_of_fragments, size);
				char current_fragment_string[100];
				strcpy(buffer, "");
				for (int i = 0; i < size; i++) {
					AnomalousFragment* current_fragment = list_of_fragments[i];
					current_fragment->toString(current_fragment_string);
					strcat(buffer, current_fragment_string);
				}
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


AnomalousFragment* Console::createFragment(char* input_id, char* input_size, char* input_infection_level, char* input_microfragments, char* input_photograph) {
	if (strcmp(input_id, "") == 0 || strcmp(input_size, "") == 0 || strcmp(input_infection_level, "") == 0 ||
		strcmp(input_microfragments, "") == 0 || strcmp(input_photograph, "") == 0) {
		throw SynataxError();
	}
	char* id = input_id;
	char dimensions[3][10];
	char* current_part = NULL;
	current_part = strtok(input_size, "Xx");
	if (current_part == NULL) {
		throw SynataxError();
	}
	strcpy(dimensions[0], current_part);
	current_part = strtok(NULL, "Xx");
	if (current_part == NULL) {
		throw SynataxError();
	}
	strcpy(dimensions[1], current_part);
	current_part = strtok(NULL, "Xx");
	if (current_part == NULL) {
		throw SynataxError();
	}
	strcpy(dimensions[2], current_part);
	triple size;
	size.length = atoi(dimensions[0]);
	size.width = atoi(dimensions[1]);
	size.height = atoi(dimensions[2]);
	double infection_level = atof(input_infection_level);
	int microfragments = atoi(input_microfragments);
	char* photograpg = input_photograph;
	AnomalousFragment* new_fragment = new AnomalousFragment(id, size, infection_level, microfragments, photograpg);
	return new_fragment;
}