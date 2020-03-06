#pragma once
#include "Model.h"


typedef struct {
	barricade** elements;
	int size;
} repository;


repository* createRepository(int number_of_elements);

void destroyRepository(repository* repository_to_destroy);

int add(repository* repository_pointer, barricade* barricade_pointer);

int update(repository* repository_pointer, int location_code, barricade* new_barricade);

int delete(repository* repository_pointer, int location_code);