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