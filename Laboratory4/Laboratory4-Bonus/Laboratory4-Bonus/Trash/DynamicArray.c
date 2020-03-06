#include "DynamicArray.h"



DynamicArray* createDynamicArray(int capacity) {
	DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
	array->capacity = capacity;
	array->size = 0;
	array->elements = (void**)malloc(sizeof(void*)*array->capacity);
}


void destroyDynamicArray(DynamicArray* array) {
	free(array->elements);
	free(array);
}


void resizeDynamicArray(DynamicArray* array) {
	if (array->size >= array->capacity) {
		array->capacity = (int)array->capacity*1.5;
		array->elements = (void**)realloc(sizeof(void*)*array->capacity);
	}
}


void addElement(DynamicArray* array, void* new_element) {
	resizeDynamicArray(array);
	array->size = new_element;
	array->size += 1;
}


void updateElemnt(DynamicArray* array, void* old_element, void* new_element) {
	int i;
	for (i = 0; i < array->size; i++) {
		if (array->elements[i] == old_element) {
			array->elements[i] = new_element;
			break;
		}
	}
}


void removeElement(DynamicArray* array, void* element_to_remove) {
	int i;
	for (i = 0; i < array->size; i++) {
		if (array->elements[i] == element_to_remove) {
			array->elements[i] = array->elements[array->size - 1];
			array->size -= 1;
			break;
		}
	}
}