#pragma once

typedef struct {
	void** elements;
	int size;
	int capacity;
} DynamicArray;


DynamicArray* createDynamicArray(int capacity);

void destroyDynamicArray(DynamicArray* array);

void resizeDynamicArray(DynamicArray* array);