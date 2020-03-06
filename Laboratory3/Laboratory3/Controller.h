#pragma once
#include "Repository.h"


typedef struct {
	repository* the_repository;
} controller;


controller* createController(repository* repository_pointer);

void destroyController(controller* controller_pointer);

int addController(controller* controller_pointer, char* location_code, char* visibility_in_area, char* barricade_type, char* barricade_sturdiness);

int updateController(controller* controller_pointer, char* location_code, char* new_visibility_in_area, char* new_barricade_type, char* new_barricade_sturdiness);

int deleteController(controller* controller_pointer, char* location_code);

void listAll(controller* controller_pointer, char* string_to_print);

void listType(controller* controller_pointer, char* test_barricade_type, char* string_to_print);

void ListByLuminosityInArea(controller* controller_pointer, char* check_luminosity, char* string_to_print);