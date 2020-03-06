#include <stdlib.h>
#include <string.h>
#include "Controller.h"



int CheckLuminosityInArea(barricade* barricade_to_check, char* luminosity) {
	return (strcmp(barricade_to_check->visibility_in_area, luminosity) == 0);
}

int filterListByGenericMatch(controller* controller_pointer, int(*filter)(barricade*, char*), char* string_to_check, barricade** results) {
	int number_of_elements = 0;
	int i;
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		if (filter(controller_pointer->the_repository->elements[i], string_to_check)) {
			results[number_of_elements] = controller_pointer->the_repository->elements[i];
			number_of_elements += 1;
		}
	}
	return number_of_elements;
}

void ListByLuminosityInArea(controller* controller_pointer, char* check_luminosity, char* string_to_print) {
	int i;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	barricade** list_of_filtered_barricades = (barricade**)malloc(sizeof(barricade*)*controller_pointer->the_repository->size);
	int size_of_list = filterListByGenericMatch(controller_pointer, CheckLuminosityInArea, check_luminosity, list_of_filtered_barricades);
	strcpy(string_to_print, "");
	for (i = 0; i < size_of_list; i++) {
		barricade* current_barricade = list_of_filtered_barricades[i];
		strcat(string_to_print, "");
		_itoa(current_barricade->location_code, location_code_string, 10);
		strcat(string_to_print, location_code_string);
		strcat(string_to_print, " ");
		strcat(string_to_print, current_barricade->visibility_in_area);
		strcat(string_to_print, " ");
		strcat(string_to_print, current_barricade->barricade_type);
		strcat(string_to_print, " ");
		_itoa(current_barricade->barricade_sturdiness, barricade_sturdiness_string, 10);
		strcat(string_to_print, barricade_sturdiness_string);
		strcat(string_to_print, "\n");
	}
	free(list_of_filtered_barricades);
}




controller* createController(repository* repository_pointer) {
	controller* new_controller = (controller*)malloc(sizeof(controller));
	new_controller->the_repository = repository_pointer;
	return new_controller;
}


void destroyController(controller* controller_pointer) {
	free(controller_pointer);
}


int addController(controller* controller_pointer, char* location_code, char* visibility_in_area, char* barricade_type, char* barricade_sturdiness) {
	int location_code_integer = atoi(location_code);
	int barricade_sturdiness_integer = atoi(barricade_sturdiness);
	barricade* new_barricade = createBarricade(location_code_integer, visibility_in_area, barricade_type, barricade_sturdiness_integer);
	return add(controller_pointer->the_repository, new_barricade);
}


int updateController(controller* controller_pointer, char* location_code, char* new_visibility_in_area, char* new_barricade_type, char* new_barricade_sturdiness) {
	int location_code_integer = atoi(location_code);
	int new_barricade_sturdiness_integer = atoi(new_barricade_sturdiness);
	barricade* new_barricade = createBarricade(location_code_integer, new_visibility_in_area, new_barricade_type, new_barricade_sturdiness_integer);
	return update(controller_pointer->the_repository, location_code_integer, new_barricade);
}


int deleteController(controller* controller_pointer, char* location_code) {
	int location_code_integer = atoi(location_code);
	return delete(controller_pointer->the_repository, location_code_integer);
}


void listAll(controller* controller_pointer, char* string_to_print) {
	int i;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	strcpy(string_to_print, "");
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		strcat(string_to_print, "");
		_itoa(controller_pointer->the_repository->elements[i]->location_code, location_code_string, 10);
		strcat(string_to_print, location_code_string);
		strcat(string_to_print, " ");
		strcat(string_to_print, controller_pointer->the_repository->elements[i]->visibility_in_area);
		strcat(string_to_print, " ");
		strcat(string_to_print, controller_pointer->the_repository->elements[i]->barricade_type);
		strcat(string_to_print, " ");
		_itoa(controller_pointer->the_repository->elements[i]->barricade_sturdiness, barricade_sturdiness_string, 10);
		strcat(string_to_print, barricade_sturdiness_string);
		strcat(string_to_print, "\n");
	}
}


void listType(controller* controller_pointer, char* test_barricade_type, char* string_to_print) {
	int i;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	strcpy(string_to_print, "");
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		if (strcmp(controller_pointer->the_repository->elements[i]->barricade_type, test_barricade_type) == 0) {
			strcat(string_to_print, "");
			_itoa(controller_pointer->the_repository->elements[i]->location_code, location_code_string, 10);
			strcat(string_to_print, location_code_string);
			strcat(string_to_print, " ");
			strcat(string_to_print, controller_pointer->the_repository->elements[i]->visibility_in_area);
			strcat(string_to_print, " ");
			strcat(string_to_print, controller_pointer->the_repository->elements[i]->barricade_type);
			strcat(string_to_print, " ");
			_itoa(controller_pointer->the_repository->elements[i]->barricade_sturdiness, barricade_sturdiness_string, 10);
			strcat(string_to_print, barricade_sturdiness_string);
			strcat(string_to_print, "\n");
		}
	}
}