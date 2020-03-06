#include "Repository.h"



Repository::Repository() {
	this->fragments = new AnomalousFragment*[1000];
	this->capacity = 1000;
	this->size = 0;
}


Repository::~Repository() {
	delete[] this->fragments;
}


bool Repository::add(AnomalousFragment* new_fragment) {
	this->resize();
	for (int i = 0; i < this->size; i++) {
		if (strcmp(this->fragments[i]->id, new_fragment->id) == 0) {
			return false;
		}
	}
	this->fragments[this->size] = new_fragment;
	this->size += 1;
	return true;
}


bool Repository::update(char* id, AnomalousFragment* new_fragment) {
	for (int i = 0; i < this->size; i++) {
		if (strcmp(this->fragments[i]->id, new_fragment->id) == 0) {
			delete this->fragments[i];
			this->fragments[i] = new_fragment;
			return true;
		}
	}
	return false;
}


bool Repository::remove(char* id) {
	for (int i = 0; i < this->size; i++) {
		if (strcmp(this->fragments[i]->id, id) == 0) {
			delete this->fragments[i];
			this->fragments[i] = this->fragments[this->size - 1];
			this->size -= 1;
			return true;
		}
	}
	return false;
}


void Repository::resize() {
	if (this->size >= this->capacity) {
		this->capacity *=1.618;
		AnomalousFragment** new_vector = new AnomalousFragment*[this->capacity];
		delete[] this->fragments;
		this->fragments = new_vector;
	}
}


int Repository::getSize() {
	return this->size;
}


AnomalousFragment* Repository::getElement(int position) {
	return this->fragments[position];
}