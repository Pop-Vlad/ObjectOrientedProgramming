#pragma once

#include "Models.h"

using namespace std;



template <typename GenericElement>
class DynamicArray {


private:

	GenericElement** elements;
	int capacity;
	int size;

	void resize();


public:

	DynamicArray();

	~DynamicArray();

	void add(GenericElement* new_element);

	void update(int position, GenericElement* new_element);

	void remove(int position);

	int getSize();

	GenericElement* getElement(int position);


};



template <typename GenericElement>
DynamicArray<GenericElement>::DynamicArray() {
	this->elements = new GenericElement*[1000];
	this->capacity = 1000;
	this->size = 0;
}


template <typename GenericElement>
DynamicArray<GenericElement>::~DynamicArray() {
	delete[] this->elements;
}


template <typename GenericElement>
void DynamicArray<GenericElement>::add(GenericElement* new_element) {
	this->resize();
	this->elements[this->size] = new_element;
	this->size += 1;
}


template <typename GenericElement>
void DynamicArray<GenericElement>::update(int position, GenericElement* new_element) {
	this->elements[position] = new_element;
}


template <typename GenericElement>
void DynamicArray<GenericElement>::remove(int position) {
	delete this->elements[position];
	this->elements[position] = this->elements[this->size - 1];
	this->size -= 1;
}


template <typename GenericElement>
void DynamicArray<GenericElement>::resize() {
	if (this->size >= this->capacity) {
		this->capacity *= 1.618;
		GenericElement** new_array = new GenericElement*[this->capacity];
		delete[] this->elements;
		this->elements = new_array;
	}
}


template <typename GenericElement>
int DynamicArray<GenericElement>::getSize() {
	return this->size;
}


template <typename GenericElement>
GenericElement* DynamicArray<GenericElement>::getElement(int position) {
	return this->elements[position];
}