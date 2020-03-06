#pragma once


typedef struct {
	int location_code;
	char* visibility_in_area;
	char* barricade_type;
	int barricade_sturdiness;
} barricade;


typedef struct {
	int operation_id;
	barricade* element_1;
	barricade* element_2;
} operation;


typedef void* GenericElement;


barricade* createBarricade(int location_code, char* visibility_in_area, char* barricade_type, int barricade_sturdiness);

void destroyBarricade(barricade* barricade_to_destroy);

operation* createOperation(int operation_id, barricade* element_1, barricade* element_2);

void destroyOperation(operation* operation_to_destroy);