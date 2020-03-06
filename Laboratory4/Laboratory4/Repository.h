#pragma once
#include "Model.h"


typedef struct {
	GenericElement* elements;
	int capacity;
	int size;
} repository;


repository* createRepository();

void destroyRepository(repository* repository_to_destroy);

int add(repository* repository_pointer, barricade* barricade_pointer);

int update(repository* repository_pointer, int location_code, barricade* new_barricade);

int delete(repository* repository_pointer, int location_code);