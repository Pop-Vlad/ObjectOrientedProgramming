#pragma once
#include "Repository.h"


typedef struct {
	repository* the_repository;
	GenericElement* hystory_of_repository;
	int hystory_of_repository_capacity;
	int hystory_of_repository_size;
	int repository_index;
} controller2;


controller2* createController2(repository* repository_pointer);

void destroyController2(controller2* controller_pointer);

int addController2(controller2* controller_pointer, char* location_code, char* visibility_in_area, char* barricade_type, char* barricade_sturdiness);

int updateController2(controller2* controller_pointer, char* location_code, char* new_visibility_in_area, char* new_barricade_type, char* new_barricade_sturdiness);

int deleteController2(controller2* controller_pointer, char* location_code);

int undo2(controller2* controller_pointer);

int redo2(controller2* controller_pointer);

void listAll2(controller2* controller_pointer, char* string_to_print);

void listType2(controller2* controller_pointer, char* test_barricade_type, char* string_to_print);

void listSturdinessAscending2(controller2* controller_pointer, char* test_barricade_sturdiness, char* string_to_print);

void listSturdinessDescending2(controller2* controller_pointer, char* test_barricade_sturdiness, char* string_to_print);


typedef struct {
	GenericElement* list_of_elements;
	int size;
	int capacity;
} PastRepositoryState;

PastRepositoryState* createRepositoryState(repository* repository);

void destroyRepositoryState(PastRepositoryState* repository_state);