#include <stdlib.h>
#include "Repository.h"


repository* createRepository(int number_of_elements) {
	repository* new_repository = (repository*)malloc(sizeof(repository));
	new_repository->size = 0;
	new_repository->elements = (barricade**)malloc(sizeof(barricade*) * number_of_elements);
	return new_repository;
}


void destroyRepository(repository* repository_to_destroy) {
	free(repository_to_destroy->elements);
	free(repository_to_destroy);
}


int add(repository* repository_pointer, barricade* barricade_pointer) {
	int i;
	for (i = 0; i < repository_pointer->size; i++) {
		if (repository_pointer->elements[i]->location_code == barricade_pointer->location_code)
			return 1;
	}
	repository_pointer->elements[repository_pointer->size] = barricade_pointer;
	repository_pointer->size += 1;
	return 0;
}


int update(repository* repository_pointer, int location_code, barricade* new_barricade) {
	int i;
	for (i = 0; i < repository_pointer->size; i++) {
		if (location_code == repository_pointer->elements[i]->location_code) {
			destroyBarricade(repository_pointer->elements[i]);
			repository_pointer->elements[i] = new_barricade;
			return 0;
		}
	}
	return 1;
}


int delete(repository* repository_pointer, int location_code) {
	int i;
	for (i = 0; i < repository_pointer->size; i++) {
		if (location_code == repository_pointer->elements[i]->location_code) {
			destroyBarricade(repository_pointer->elements[i]);
			repository_pointer->elements[i] = repository_pointer->elements[repository_pointer->size - 1];
			repository_pointer->size -= 1;
			return 0;
		}
	}
	return 1;
}