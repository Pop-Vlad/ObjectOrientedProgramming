#include <string.h>
#include <stdlib.h>
#include "Model.h"


barricade* createBarricade(int location_code, char* visibility_in_area, char* barricade_type, int barricade_sturdiness) {
	barricade* new_barricade = (barricade*)malloc(sizeof(barricade));
	new_barricade->location_code = location_code;
	new_barricade->visibility_in_area = (char*)malloc(sizeof(char) * (strlen(visibility_in_area) + 1));
	strcpy(new_barricade->visibility_in_area, visibility_in_area);
	new_barricade->barricade_type = (char*)malloc(sizeof(char) * (strlen(barricade_type) + 1));
	strcpy(new_barricade->barricade_type, barricade_type);
	new_barricade->barricade_sturdiness = barricade_sturdiness;
	return new_barricade;
}


void destroyBarricade(barricade* barricade_to_destroy) {
	free(barricade_to_destroy->visibility_in_area);
	free(barricade_to_destroy->barricade_type);
	free(barricade_to_destroy);
}


operation* createOperation(int operation_id, barricade* element_1, barricade* element_2) {
	operation* new_operation = (operation*)malloc(sizeof(operation));
	new_operation->operation_id = operation_id;
	if (element_1 != NULL) {
		new_operation->element_1 = createBarricade(element_1->location_code, element_1->visibility_in_area, element_1->barricade_type,
			element_1->barricade_sturdiness);
	}
	else {
		new_operation->element_1 = NULL;
	}
	if (element_2 != NULL) {
		new_operation->element_2= createBarricade(element_2->location_code, element_2->visibility_in_area, element_2->barricade_type,
			element_2->barricade_sturdiness);
	}
	else {
		new_operation->element_2 = NULL;
	}
	return new_operation;
}


void destroyOperation(operation* operation_to_destroy) {
	if (operation_to_destroy->element_1 != NULL) {
		destroyBarricade(operation_to_destroy->element_1);
	}
	if (operation_to_destroy->element_2 != NULL) {
		destroyBarricade(operation_to_destroy->element_2);
	}
	free(operation_to_destroy);
}