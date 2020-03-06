#pragma once


typedef struct {
	int location_code;
	char* visibility_in_area;
	char* barricade_type;
	int barricade_sturdiness;
} barricade;


barricade* createBarricade(int location_code, char* visibility_in_area, char* barricade_type, int barricade_sturdiness);

void destroyBarricade(barricade* barricade_to_destroy);