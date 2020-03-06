#include "Repository.h"



Repository::Repository() {
	this->fragments = new DynamicArray<AnomalousFragment>;
}


Repository::~Repository() {
	delete this->fragments;
}


bool Repository::add(AnomalousFragment* new_fragment) {
	for (int i = 0; i < this->fragments->getSize(); i++) {
		if (strcmp(this->fragments->getElement(i)->id, new_fragment->id) == 0) {
			return false;
		}
	}
	this->fragments->add(new_fragment);
	return true;
}


bool Repository::update(char* id, AnomalousFragment* new_fragment) {
	for (int i = 0; i < this->fragments->getSize(); i++) {
		if (strcmp(this->fragments->getElement(i)->id, new_fragment->id) == 0) {
			this->fragments->update(i, new_fragment);
			return true;
		}
	}
	return false;
}


bool Repository::remove(char* id) {
	for (int i = 0; i < this->fragments->getSize(); i++) {
		if (strcmp(this->fragments->getElement(i)->id, id) == 0) {
			this->fragments->remove(i);
			return true;
		}
	}
	return false;
}


int Repository::getSize() {
	return this->fragments->getSize();
}


AnomalousFragment* Repository::getElement(int position) {
	return this->fragments->getElement(position);
}