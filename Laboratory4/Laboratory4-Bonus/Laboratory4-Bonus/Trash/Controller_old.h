#pragma once
#include "Repository.h"


typedef struct {
	repository* the_repository;
	GenericElement* operations_list;
	int operation_list_capacity;
	int operations_list_size;
	int operation_index;
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