#include "Controller.h"



Controller::Controller(Repository<AnomalousFragment>* repository) {
	this->repository = repository;
	this->mode = NULL;
	this->user_list_capacity = 10;
	this->user_list_size = 0;
	this->user_list = new AnomalousFragment*[10];
	this->current_fragment_index = -1;
}


Controller::~Controller() {
	for (int i = 0; i < this->user_list_size; i++) {
		delete this->user_list[i];
	}
	delete[] this->user_list;
}


bool Controller::changeMode(char* new_mode) {
	if (strlen(new_mode) != 1) {
		return false;
	}
	if (new_mode[0] == 'a' || new_mode[0] == 'A') {
		this->mode = 'A';
		return true;
	}
	if (new_mode[0] == 'b' || new_mode[0] == 'B') {
		this->mode = 'B';
		return true;
	}
	return false;
}


char Controller::getMode() {
	return this->mode;
}


bool Controller::add(char* input_id, char* input_size, char* input_infection_level, char* input_microfragments, char* input_photograph) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
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
	return this->repository->add(new_fragment);
}


bool Controller::update(char* input_id, char* input_new_size, char* input_new_infection_level, char* input_new_microfragments, char* input_new_photograph) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
	if (strcmp(input_id, "") == 0 || strcmp(input_new_size, "") == 0 || strcmp(input_new_infection_level, "") == 0 ||
		strcmp(input_new_microfragments, "") == 0 || strcmp(input_new_photograph, "") == 0) {
		throw SynataxError();
	}
	char* id = input_id;
	char dimensions[3][10];
	char* current_part = NULL;
	current_part = strtok(input_new_size, "Xx");
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
	double infection_level = atof(input_new_infection_level);
	int microfragments = atoi(input_new_microfragments);
	char* photograpg = input_new_photograph;
	AnomalousFragment* new_fragment = new AnomalousFragment(id, size, infection_level, microfragments, photograpg);
	return this->repository->update(id, new_fragment);
}


bool Controller::remove(char* input_id) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
	char* id = input_id;
	return this->repository->remove(id);
}


void Controller::listAll(char* buffer) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
	char current_fragment_string[100];
	strcpy(buffer, "");
	for (int i = 0; i < this->repository->getSize(); i++) {
		AnomalousFragment* current_fragment = this->repository->getElement(i);
		current_fragment->toString(current_fragment_string);
		strcat(buffer, current_fragment_string);
	}
}


void Controller::resizeUserList() {
	if (this->user_list_size >= this->user_list_capacity) {
		this->user_list_capacity *= 1.618;
		AnomalousFragment** new_list = new AnomalousFragment*[this->user_list_capacity];
		delete[] this->user_list;
		this->user_list = new_list;
	}
}


void Controller::nextFragment(char* buffer) {
	if (this->mode != 'B') {
		throw PermisiisionError();
	}
	if (this->repository->getSize() == 0) {
		strcpy(buffer, "\n");
		return;
	}
	if (this->current_fragment_index >= this->repository->getSize() - 1) {
		this->current_fragment_index = -1;
	}
	this->current_fragment_index += 1;
	char current_fragment_string[100];
	this->repository->getElement(this->current_fragment_index)->toString(current_fragment_string);
	strcpy(buffer, current_fragment_string);
	strcat(buffer, "\n");
}


bool Controller::saveFragment(char* input_id) {
	if (this->mode != 'B') {
		throw PermisiisionError();
	}
	if (strcmp(input_id, "") == 0) {
		throw SynataxError();
	}
	for (int i = 0; i < this->repository->getSize(); i++) {
		if (strcmp(this->repository->getElement(i)->id, input_id) == 0) {
			AnomalousFragment* fragment_to_copy = this->repository->getElement(i);
			AnomalousFragment* new_fragment = new AnomalousFragment(fragment_to_copy->id, fragment_to_copy->size, fragment_to_copy->infection_level,
				fragment_to_copy->microfragments, fragment_to_copy->photograph);
			this->resizeUserList();
			this->user_list[this->user_list_size] = new_fragment;
			this->user_list_size += 1;
			return true;
		}
	}
	return false;
}


void Controller::listSize(char* buffer, char* input_size, char* input_minimum_microfragments) {
	if (this->mode != 'B') {
		throw PermisiisionError();
	}
	if (strcmp(input_size, "") == 0 || strcmp(input_minimum_microfragments, "") == 0) {
		throw SynataxError();
	}
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
	int microfragments = atoi(input_minimum_microfragments);

	char current_fragment_string[100];
	strcpy(buffer, "");
	for (int i = 0; i < this->repository->getSize(); i++) {
		AnomalousFragment* current_element = this->repository->getElement(i);
		if (current_element->size.length == size.length && current_element->size.width == size.width && current_element->size.height == size.height &&
			current_element->microfragments >= microfragments) {
			this->repository->getElement(i)->toString(current_fragment_string);
			strcat(buffer, current_fragment_string);
		}
	}
}


void Controller::showUserList(char* buffer) {
	if (this->mode != 'B') {
		throw PermisiisionError();
	}
	char current_fragment_string[100];
	strcpy(buffer, "");
	for (int i = 0; i < this->user_list_size; i++) {
		this->user_list[i]->toString(current_fragment_string);
		strcat(buffer, current_fragment_string);
	}
}