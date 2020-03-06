#pragma once
#include "Repository.h"


typedef struct {
	repository* the_repository;
	GenericElement* hystory_of_repository;
	int hystory_of_repository_capacity;
	int hystory_of_repository_size;
	int repository_index;
} controller;


controller* createController(repository* repository_pointer);

void destroyController(controller* controller_pointer);

int addController(controller* controller_pointer, char* location_code, char* visibility_in_area, char* barricade_type, char* barricade_sturdiness);

int updateController(controller* controller_pointer, char* location_code, char* new_visibility_in_area, char* new_barricade_type, char* new_barricade_sturdiness);

int deleteController(controller* controller_pointer, char* location_code);

int undo(controller* controller_pointer);

int redo(controller* controller_pointer);

void listAll(controller* controller_pointer, char* string_to_print);

void listType(controller* controller_pointer, char* test_barricade_type, char* string_to_print);

void listSturdinessAscending(controller* controller_pointer, char* test_barricade_sturdiness, char* string_to_print);

void listSturdinessDescending(controller* controller_pointer, char* test_barricade_sturdiness, char* string_to_print);


typedef struct {
	GenericElement* list_of_elements;
	int size;
	int capacity;
} PastRepositoryState;

PastRepositoryState* createRepositoryState(repository* repository);

void destroyRepositoryState(PastRepositoryState* repository_state);