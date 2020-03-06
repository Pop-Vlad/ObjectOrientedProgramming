#include "MemoryRepository.h"



Repository::Repository() {
	this->fragments = new std::vector<AnomalousFragment*>;
}


Repository::~Repository() {
	delete this->fragments;
}


bool Repository::add(AnomalousFragment* new_fragment) {
	std::vector<AnomalousFragment*>::iterator iterator = std::find_if(this->fragments->begin(), this->fragments->end(), [new_fragment](AnomalousFragment* fragment) { return strcmp(fragment->id, new_fragment->id) == 0; });
	if (iterator != this->fragments->end()) {
		return false;
	}
	this->fragments->push_back(new_fragment);
	return true;
}


bool Repository::update(char* id, AnomalousFragment* new_fragment) {
	std::vector<AnomalousFragment*>::iterator iterator = std::find_if(this->fragments->begin(), this->fragments->end(), [new_fragment](AnomalousFragment* fragment) { return strcmp(fragment->id, new_fragment->id) == 0; });
	if (iterator != this->fragments->end()) {
		delete *iterator;
		*iterator = new_fragment;
		return true;
	}
	return false;
}


bool Repository::remove(char* id) {
	std::vector<AnomalousFragment*>::iterator iterator = std::find_if(this->fragments->begin(), this->fragments->end(), [id](AnomalousFragment* fragment) { return strcmp(fragment->id, id) == 0; });
	if (iterator != this->fragments->end()) {
		delete *iterator;
		*iterator = this->fragments->at(this->fragments->size() - 1);
		this->fragments->pop_back();
		return true;
	}
	return false;
}


int Repository::getSize() {
	return this->fragments->size();
}


AnomalousFragment* Repository::getElement(int position) {
	return this->fragments->at(position);
}