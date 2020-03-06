#include <stdlib.h>
#include <string.h>
#include "Controller.h"



void registerOperation(controller* controller_pointer, GenericElement new_operation) {

	if (controller_pointer->operation_list_capacity >= controller_pointer->operation_list_capacity) {
		controller_pointer->operations_list = (GenericElement*)realloc(controller_pointer->operations_list, (int)controller_pointer->operation_list_capacity * 1.5 * (sizeof(GenericElement)));
	}

	int i;
	for (i = controller_pointer->operation_index + 1; i < controller_pointer->operations_list_size; i++) {
		destroyOperation(controller_pointer->operations_list[i]);
	}
	controller_pointer->operation_index += 1;
	controller_pointer->operations_list_size = controller_pointer->operation_index + 1;
	controller_pointer->operations_list[controller_pointer->operation_index] = new_operation;
}


int compareBarricadesByVisibility(barricade* object_1, barricade* object_2) {
	return strcmp(object_1->visibility_in_area, object_2->visibility_in_area);
}


void sortAscending(barricade** list_of_barricades, int list_length, int(*key)(barricade*, barricade*)) {
	barricade* auxiliary_pointer = NULL;
	int i, j;
	for (i = 0; i < list_length; i++) {
		for (j = 0; j < list_length; j++) {
			if (key(list_of_barricades[i], list_of_barricades[j]) < 0) {
				auxiliary_pointer = list_of_barricades[i];
				list_of_barricades[i] = list_of_barricades[j];
				list_of_barricades[j] = auxiliary_pointer;
			}
		}
	}
}


void sortDescending(barricade** list_of_barricades, int list_length, int(*key)(barricade*, barricade*)) {
	barricade* auxiliary_pointer = NULL;
	int i, j;
	for (i = 0; i < list_length; i++) {
		for (j = 0; j < list_length; j++) {
			if (key(list_of_barricades[i], list_of_barricades[j]) > 0) {
				auxiliary_pointer = list_of_barricades[i];
				list_of_barricades[i] = list_of_barricades[j];
				list_of_barricades[j] = auxiliary_pointer;
			}
		}
	}
}



controller* createController(repository* repository_pointer) {
	controller* new_controller = (controller*)malloc(sizeof(controller));
	new_controller->the_repository = repository_pointer;
	new_controller->operations_list = (GenericElement*)malloc(sizeof(GenericElement) * 100);
	new_controller->operation_list_capacity = 100;
	new_controller->operations_list_size = 0;
	new_controller->operation_index = -1;
	return new_controller;
}


void destroyController(controller* controller_pointer) {
	int i;
	for (i = 0; i < controller_pointer->operations_list_size; i++) {
		destroyOperation(controller_pointer->operations_list[i]);
	}
	free(controller_pointer->operations_list);
	free(controller_pointer);
}



int addController(controller* controller_pointer, char* location_code, char* visibility_in_area, char* barricade_type, char* barricade_sturdiness) {
	int return_status;
	int location_code_integer = atoi(location_code);
	int barricade_sturdiness_integer = atoi(barricade_sturdiness);
	barricade* new_barricade = createBarricade(location_code_integer, visibility_in_area, barricade_type, barricade_sturdiness_integer);
	return_status = add(controller_pointer->the_repository, new_barricade);
	if (return_status == 0) {
		GenericElement new_operation = createOperation(1, new_barricade, NULL);
		registerOperation(controller_pointer, new_operation);
	}
	return return_status;
}


int updateController(controller* controller_pointer, char* location_code, char* new_visibility_in_area, char* new_barricade_type, char* new_barricade_sturdiness) {
	int return_status;
	int location_code_integer = atoi(location_code);
	int new_barricade_sturdiness_integer = atoi(new_barricade_sturdiness);
	GenericElement new_operation = NULL;
	barricade* old_barricade = NULL;

	int i;
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		barricade* barricade_to_check = (barricade*)controller_pointer->the_repository->elements[i];
		if (location_code_integer == barricade_to_check->location_code) {
			old_barricade = createBarricade(barricade_to_check->location_code,
				barricade_to_check->visibility_in_area,
				barricade_to_check->barricade_type,
				barricade_to_check->barricade_sturdiness);
			break;
		}
	}

	barricade* new_barricade = createBarricade(location_code_integer, new_visibility_in_area, new_barricade_type, new_barricade_sturdiness_integer);
	return_status = update(controller_pointer->the_repository, location_code_integer, new_barricade);
	if (return_status == 0) {
		new_operation = createOperation(2, old_barricade, new_barricade);
		registerOperation(controller_pointer, new_operation);
		destroyBarricade(old_barricade);
	}
	return return_status;
}


int deleteController(controller* controller_pointer, char* location_code) {
	int return_status;
	int location_code_integer = atoi(location_code);
	GenericElement new_operation = NULL;
	barricade* deleted_barricade = NULL;

	int i;
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		barricade* barricade_to_check = (barricade*)controller_pointer->the_repository->elements[i];
		if (location_code_integer == barricade_to_check->location_code) {
			deleted_barricade = createBarricade(barricade_to_check->location_code,
				barricade_to_check->visibility_in_area,
				barricade_to_check->barricade_type,
				barricade_to_check->barricade_sturdiness);
			break;
		}
	}

	return_status = delete(controller_pointer->the_repository, location_code_integer);
	if (return_status == 0) {
		new_operation = createOperation(3, deleted_barricade, NULL);
		registerOperation(controller_pointer, new_operation);
		destroyBarricade(deleted_barricade);
	}
	return return_status;
}



int undo(controller* controller_pointer) {
	if (controller_pointer->operation_index < 0) {
		return 0;
	}
	operation* current_operation = (operation*)controller_pointer->operations_list[controller_pointer->operation_index];
	if (current_operation->operation_id == 1) {
		delete(controller_pointer->the_repository, current_operation->element_1->location_code);
		controller_pointer->operation_index -= 1;
		return 1;
	}
	if (current_operation->operation_id == 2) {
		barricade* element_1_copy = createBarricade(current_operation->element_1->location_code, current_operation->element_1->visibility_in_area,
			current_operation->element_1->barricade_type, current_operation->element_1->barricade_sturdiness);
		update(controller_pointer->the_repository, current_operation->element_2->location_code, element_1_copy);
		controller_pointer->operation_index -= 1;
		return 2;
	}
	if (current_operation->operation_id == 3) {
		barricade* element_1_copy = createBarricade(current_operation->element_1->location_code, current_operation->element_1->visibility_in_area,
			current_operation->element_1->barricade_type, current_operation->element_1->barricade_sturdiness);
		add(controller_pointer->the_repository, element_1_copy);
		controller_pointer->operation_index -= 1;
		return 3;
	}
	return -1;
}


int redo(controller* controller_pointer) {
	if (controller_pointer->operation_index >= controller_pointer->operations_list_size - 1) {
		return 0;
	}
	operation* current_operation = (operation*)controller_pointer->operations_list[controller_pointer->operation_index + 1];
	if (current_operation->operation_id == 1) {
		barricade* element_1_copy = createBarricade(current_operation->element_1->location_code, current_operation->element_1->visibility_in_area,
			current_operation->element_1->barricade_type, current_operation->element_1->barricade_sturdiness);
		add(controller_pointer->the_repository, element_1_copy);
		controller_pointer->operation_index += 1;
		return 1;
	}
	if (current_operation->operation_id == 2) {
		barricade* element_2_copy = createBarricade(current_operation->element_2->location_code, current_operation->element_2->visibility_in_area,
			current_operation->element_2->barricade_type, current_operation->element_2->barricade_sturdiness);
		update(controller_pointer->the_repository, current_operation->element_1->location_code, element_2_copy);
		controller_pointer->operation_index += 1;
		return 2;
	}
	if (current_operation->operation_id == 3) {
		delete(controller_pointer->the_repository, current_operation->element_1->location_code);
		controller_pointer->operation_index += 1;
		return 3;
	}
	return -1;
}



void listAll(controller* controller_pointer, char* string_to_print) {
	int i;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	strcpy(string_to_print, "");
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		barricade* barricade_to_check = (barricade*)controller_pointer->the_repository->elements[i];
		_itoa(barricade_to_check->location_code, location_code_string, 10);
		strcat(string_to_print, location_code_string);
		strcat(string_to_print, " ");
		strcat(string_to_print, barricade_to_check->visibility_in_area);
		strcat(string_to_print, " ");
		strcat(string_to_print, barricade_to_check->barricade_type);
		strcat(string_to_print, " ");
		_itoa(barricade_to_check->barricade_sturdiness, barricade_sturdiness_string, 10);
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
		barricade* barricade_to_check = (barricade*)controller_pointer->the_repository->elements[i];
		if (strcmp(barricade_to_check->barricade_type, test_barricade_type) == 0) {
			_itoa(barricade_to_check->location_code, location_code_string, 10);
			strcat(string_to_print, location_code_string);
			strcat(string_to_print, " ");
			strcat(string_to_print, barricade_to_check->visibility_in_area);
			strcat(string_to_print, " ");
			strcat(string_to_print, barricade_to_check->barricade_type);
			strcat(string_to_print, " ");
			_itoa(barricade_to_check->barricade_sturdiness, barricade_sturdiness_string, 10);
			strcat(string_to_print, barricade_sturdiness_string);
			strcat(string_to_print, "\n");
		}
	}
}


void listSturdinessAscending(controller* controller_pointer, char* test_barricade_sturdiness, char* string_to_print) {
	int i;
	barricade* list_of_filtered_barricades[1000];
	int length = 0;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	int test_barricade_sturdiness_integer = atoi(test_barricade_sturdiness);
	strcpy(string_to_print, "");

	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		barricade* barricade_to_check = (barricade*)controller_pointer->the_repository->elements[i];
		if (barricade_to_check->barricade_sturdiness <= test_barricade_sturdiness_integer) {
			list_of_filtered_barricades[length] = controller_pointer->the_repository->elements[i];
			length += 1;
		}
	}

	sortAscending(list_of_filtered_barricades, length, compareBarricadesByVisibility);

	for (i = 0; i < length; i++) {
		_itoa(list_of_filtered_barricades[i]->location_code, location_code_string, 10);
		strcat(string_to_print, location_code_string);
		strcat(string_to_print, " ");
		strcat(string_to_print, list_of_filtered_barricades[i]->visibility_in_area);
		strcat(string_to_print, " ");
		strcat(string_to_print, list_of_filtered_barricades[i]->barricade_type);
		strcat(string_to_print, " ");
		_itoa(list_of_filtered_barricades[i]->barricade_sturdiness, barricade_sturdiness_string, 10);
		strcat(string_to_print, barricade_sturdiness_string);
		strcat(string_to_print, "\n");
	}
}


void listSturdinessDescending(controller* controller_pointer, char* test_barricade_sturdiness, char* string_to_print) {
	int i;
	barricade* list_of_filtered_barricades[1000];
	int length = 0;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	int test_barricade_sturdiness_integer = atoi(test_barricade_sturdiness);
	strcpy(string_to_print, "");

	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		barricade* barricade_to_check = (barricade*)controller_pointer->the_repository->elements[i];
		if (barricade_to_check->barricade_sturdiness <= test_barricade_sturdiness_integer) {
			list_of_filtered_barricades[length] = controller_pointer->the_repository->elements[i];
			length += 1;
		}
	}

	sortDescending(list_of_filtered_barricades, length, compareBarricadesByVisibility);

	for (i = 0; i < length; i++) {
		_itoa(list_of_filtered_barricades[i]->location_code, location_code_string, 10);
		strcat(string_to_print, location_code_string);
		strcat(string_to_print, " ");
		strcat(string_to_print, list_of_filtered_barricades[i]->visibility_in_area);
		strcat(string_to_print, " ");
		strcat(string_to_print, list_of_filtered_barricades[i]->barricade_type);
		strcat(string_to_print, " ");
		_itoa(list_of_filtered_barricades[i]->barricade_sturdiness, barricade_sturdiness_string, 10);
		strcat(string_to_print, barricade_sturdiness_string);
		strcat(string_to_print, "\n");
	}
}