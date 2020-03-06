#include "Repository.h"



template <typename GenericElement>
Repository<GenericElement>::Repository() {
	this->fragments = new GenericElement*[1000];
	this->capacity = 1000;
	this->size = 0;
}


template <typename GenericElement>
Repository<GenericElement>::~Repository() {
	delete[] this->fragments;
}


template <typename GenericElement>
bool Repository<GenericElement>::add(GenericElement* new_fragment) {
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


template <typename GenericElement>
bool Repository<GenericElement>::update(char* id, GenericElement* new_fragment) {
	for (int i = 0; i < this->size; i++) {
		if (strcmp(this->fragments[i]->id, new_fragment->id) == 0) {
			delete this->fragments[i];
			this->fragments[i] = new_fragment;
			return true;
		}
	}
	return false;
}


template <typename GenericElement>
bool Repository<GenericElement>::remove(char* id) {
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


template <typename GenericElement>
void Repository<GenericElement>::resize() {
	if (this->size >= this->capacity) {
		this->capacity *=1.618;
		GenericElement** new_vector = new GenericElement*[this->capacity];
		delete[] this->fragments;
		this->fragments = new_vector;
	}
}


template <typename GenericElement>
int Repository<GenericElement>::getSize() {
	return this->size;
}


template <typename GenericElement>
GenericElement* Repository<GenericElement>::getElement(int position) {
	return this->fragments[position];
}