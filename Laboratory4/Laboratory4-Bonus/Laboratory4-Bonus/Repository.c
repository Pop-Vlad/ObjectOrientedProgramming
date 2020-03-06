#include <stdlib.h>
#include "Repository.h"


repository* createRepository() {
	repository* new_repository = (repository*)malloc(sizeof(repository));
	new_repository->capacity = 100;
	new_repository->size = 0;
	new_repository->elements = (GenericElement*)malloc(sizeof(GenericElement) * 100);
	return new_repository;
}


void destroyRepository(repository* repository_to_destroy) {
	int i;
	for (i = 0; i < repository_to_destroy->size; i++) {
		destroyBarricade(repository_to_destroy->elements[i]);
	}
	free(repository_to_destroy->elements);
	free(repository_to_destroy);
}


int add(repository* repository_pointer, barricade* barricade_pointer) {
	
	if (repository_pointer->size >= repository_pointer->capacity) {
		repository_pointer->capacity = (int)repository_pointer->capacity*1.5;
		repository_pointer->elements = (GenericElement*)realloc(repository_pointer->elements, sizeof(GenericElement) * repository_pointer->capacity);
	}
	
	int i;
	for (i = 0; i < repository_pointer->size; i++) {
		barricade* barricade_to_check = (barricade*)repository_pointer->elements[i];
		if (barricade_to_check->location_code == barricade_pointer->location_code)
			return 1;
	}
	repository_pointer->elements[repository_pointer->size] = barricade_pointer;
	repository_pointer->size += 1;
	return 0;
}


int update(repository* repository_pointer, int location_code, barricade* new_barricade) {
	int i;
	for (i = 0; i < repository_pointer->size; i++) {
		barricade* barricade_to_check = (barricade*)repository_pointer->elements[i];
		if (location_code == barricade_to_check->location_code) {
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
		barricade* barricade_to_check = (barricade*)repository_pointer->elements[i];
		if (location_code == barricade_to_check->location_code) {
			destroyBarricade(repository_pointer->elements[i]);
			repository_pointer->elements[i] = repository_pointer->elements[repository_pointer->size - 1];
			repository_pointer->size -= 1;
			return 0;
		}
	}
	return 1;
}