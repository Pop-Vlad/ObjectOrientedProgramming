


/*
void listAll(controller* controller_pointer, char* string_to_print) {
	int i;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	strcpy(string_to_print, "");
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		strcat(string_to_print, "Location code: ");
		_itoa(controller_pointer->the_repository->elements[i]->location_code, location_code_string, 10);
		strcat(string_to_print, location_code_string);
		strcat(string_to_print, ", visibility in area: ");
		strcat(string_to_print, controller_pointer->the_repository->elements[i]->visibility_in_area);
		strcat(string_to_print, ", barricade type: ");
		strcat(string_to_print, controller_pointer->the_repository->elements[i]->barricade_type);
		strcat(string_to_print, ", barricade sturdiness: ");
		_itoa(controller_pointer->the_repository->elements[i]->barricade_sturdiness, barricade_sturdiness_string, 10);
		strcat(string_to_print, barricade_sturdiness_string);
		strcat(string_to_print, "\n");
	}
}


void listType(controller* controller_pointer, char* test_barricade_type, char* string_to_print) {
	int i;
	char location_code_string[20];
	char barricade_sturdiness_string[20];
	for (i = 0; i < controller_pointer->the_repository->size; i++) {
		if (strcmp(controller_pointer->the_repository->elements[i]->barricade_type, test_barricade_type) == 0) {
			strcpy(string_to_print, "Location code: ");
			_itoa(controller_pointer->the_repository->elements[i]->location_code, location_code_string, 10);
			strcat(string_to_print, location_code_string);
			strcat(string_to_print, ", visibility in area: ");
			strcpy(string_to_print, controller_pointer->the_repository->elements[i]->visibility_in_area);
			strcat(string_to_print, ", barricade type: ");
			strcpy(string_to_print, controller_pointer->the_repository->elements[i]->barricade_type);
			strcat(string_to_print, ", barricade sturdiness: ");
			_itoa(controller_pointer->the_repository->elements[i]->barricade_sturdiness, barricade_sturdiness_string, 10);
			strcat(string_to_print, barricade_sturdiness_string);
			strcat(string_to_print, "\n");
		}
	}
}
*/