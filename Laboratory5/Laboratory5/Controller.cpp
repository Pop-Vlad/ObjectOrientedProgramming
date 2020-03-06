#include "Controller.h"



Controller::Controller(Repository* repository) {
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


bool Controller::add(AnomalousFragment* new_fragment) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
	
	return this->repository->add(new_fragment);
}


bool Controller::update(AnomalousFragment* new_fragment) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
	char* id_of_fragment_to_update = new_fragment->id;
	return this->repository->update(id_of_fragment_to_update, new_fragment);
}


bool Controller::remove(char* input_id) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
	char* id = input_id;
	return this->repository->remove(id);
}


void Controller::listAll(AnomalousFragment** list_of_fragment, int& size) {
	if (this->mode != 'A') {
		throw PermisiisionError();
	}
	


	for (int i = 0; i < this->repository->getSize(); i++) {
		list_of_fragment[i] = this->repository->getElement(i);
	}
	size = this->repository->getSize();
}


void Controller::resizeUserList() {
	if (this->user_list_size >= this->user_list_capacity) {
		this->user_list_capacity *= 1.618;
		AnomalousFragment** new_list = new AnomalousFragment*[this->user_list_capacity];
		delete[] this->user_list;
		this->user_list = new_list;
	}
}


AnomalousFragment* Controller::nextFragment() {
	if (this->mode != 'B') {
		throw PermisiisionError();
	}
	if (this->repository->getSize() == 0) {
		return NULL;
	}
	if (this->current_fragment_index >= this->repository->getSize() - 1) {
		this->current_fragment_index = -1;
	}
	this->current_fragment_index += 1;
	return this->repository->getElement(this->current_fragment_index);
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


void Controller::listSize(AnomalousFragment** list_of_fragments, int& size, AnomalousFragment* fragment_to_compare) {
	if (this->mode != 'B') {
		throw PermisiisionError();
	}
	size = 0;
	for (int i = 0; i < this->repository->getSize(); i++) {
		AnomalousFragment* current_element = this->repository->getElement(i);
		if (current_element->size.length == fragment_to_compare->size.length && current_element->size.width == fragment_to_compare->size.width &&
			current_element->size.height == fragment_to_compare->size.height && current_element->microfragments >= fragment_to_compare->microfragments) {
			list_of_fragments[size] = current_element;
			size += 1;
		}
	}
}


void Controller::showUserList(AnomalousFragment** list_of_fragments, int& size) {
	if (this->mode != 'B') {
		throw PermisiisionError();
	}
	list_of_fragments = this->user_list;
	size = this->user_list_size;
}