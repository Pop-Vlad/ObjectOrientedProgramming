#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Console.h"


console* createConsole(controller* controller_pointer) {
	console* new_console = (console*)malloc(sizeof(console));
	new_console->the_controller = controller_pointer;
	return new_console;
}


void destroyConsole(console* console_pointer) {
	free(console_pointer);
}


void readCommand(char command[5][20])
{
	char input[100];
	char* token;
	const char delimiter[] = ", ";
	int length = 0;
	int i;

	for (i = 0; i < 5; i++) {
		command[i][0] = '\0';
	}

	scanf(" %[^\n]s", input);
	token = strtok(input, delimiter);

	while (token != NULL && length < 5)
	{
		strcpy(command[length], token);
		length += 1;
		token = strtok(NULL, delimiter);
	}
	//printf("%s_%s_%s_%s_%s", command[0], command[1], command[2], command[3], command[4]);
}


void run(console* console_pointer) {
	char string_to_print[1000];
	char command[5][20];
	int return_status;

	while (1) {

		readCommand(command);

		if (strcmp(command[0], "add") == 0) {
			return_status = addController(console_pointer->the_controller, command[1], command[2], command[3], command[4]);
			if (return_status == 0)
				printf("Barricade successfully added.\n\n");
			else
				printf("Cannot add new element.\n\n");
		}
		if (strcmp(command[0], "update") == 0) {
			return_status = updateController(console_pointer->the_controller, command[1], command[2], command[3], command[4]);
			if (return_status == 0)
				printf("Barricade successfully updated.\n\n");
			else
				printf("Cannot update element.\n\n");
		}
		if (strcmp(command[0], "delete") == 0) {
			return_status = deleteController(console_pointer->the_controller, command[1]);
			if (return_status == 0)
				printf("Barricade successfully deleted.\n\n");
			else
				printf("Cannot delete element.\n\n");
		}
		if (strcmp(command[0], "list") == 0 && command[1][0] == '\0') {
			listAll(console_pointer->the_controller, string_to_print);
			printf("%s\n\n", string_to_print);
		}
		if (strcmp(command[0], "list") == 0 && command[1][0] != '\0') {
			if (strcmp(command[1], "luminosity") == 0) {
				ListByLuminosityInArea(console_pointer->the_controller, command[2], string_to_print);
				printf("%s\n\n", string_to_print);
			}
			else {
				listType(console_pointer->the_controller, command[1], string_to_print);
				printf("%s\n\n", string_to_print);
			}
		}
		if (strcmp(command[0], "exit") == 0) {
			break;
		}
	}
}