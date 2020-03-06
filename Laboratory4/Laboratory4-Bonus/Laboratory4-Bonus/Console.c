#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Console.h"


console* createConsole(void* controller_pointer, int controller_type) {
	console* new_console = (console*)malloc(sizeof(console));
	new_console->the_controller = (controller*)controller_pointer;
	return new_console;
}


void destroyConsole(console* console_pointer) {
	free(console_pointer);
}


void readCommand(char command[10][20])
{
	char input[200];
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
}


void run(console* console_pointer) {
	char string_to_print[20000];
	char command[10][20];
	int return_status;
	int command_is_valid;

	while (1) {

		command_is_valid = 0;
		readCommand(command);

		if (strcmp(command[0], "add") == 0) {
			return_status = addController(console_pointer->the_controller, command[1], command[2], command[3], command[4]);
			if (return_status == 0)
				printf("Barricade successfully added.\n\n");
			else
				printf("Cannot add new element.\n\n");
			command_is_valid = 1;
		}
		if (strcmp(command[0], "update") == 0) {
			return_status = updateController(console_pointer->the_controller, command[1], command[2], command[3], command[4]);
			if (return_status == 0)
				printf("Barricade successfully updated.\n\n");
			else
				printf("Cannot update element.\n\n");
			command_is_valid = 1;
		}
		if (strcmp(command[0], "delete") == 0) {
			return_status = deleteController(console_pointer->the_controller, command[1]);
			if (return_status == 0)
				printf("Barricade successfully deleted.\n\n");
			else
				printf("Cannot delete element.\n\n");
			command_is_valid = 1;
		}
		if (strcmp(command[0], "undo") == 0) {
			return_status = undo(console_pointer->the_controller);
			if (return_status == 0)
				printf("Nothing to undo.\n\n");
			if(return_status == 1)
				printf("Add operation successfully undone.\n\n");
			if (return_status == 2)
				printf("Update operation successfully undone.\n\n");
			if (return_status == 3)
				printf("Delete operation successfully undone.\n\n");
			command_is_valid = 1;
			if (return_status == 4)
				printf("Undo successfully performed.\n\n");
			command_is_valid = 1;
		}
		if (strcmp(command[0], "redo") == 0) {
			return_status = redo(console_pointer->the_controller);
			if (return_status == 0)
				printf("Nothing to redo.\n\n");
			if (return_status == 1)
				printf("Add operation successfully redone.\n\n");
			if (return_status == 2)
				printf("Update operation successfully redone.\n\n");
			if (return_status == 3)
				printf("Delete operation successfully redone.\n\n");
			command_is_valid = 1;
			if (return_status == 4)
				printf("Undo successfully performed.\n\n");
			command_is_valid = 1;
		}
		if (strcmp(command[0], "list") == 0 && command[1][0] == '\0') {
			listAll(console_pointer->the_controller, string_to_print);
			printf("%s\n", string_to_print);
			command_is_valid = 1;
		}
		if ((strcmp(command[0], "list") == 0) && (command[1][0] >= 'A' ) && (command[1][0] <= 'z')) {
			listType(console_pointer->the_controller, command[1], string_to_print);
			printf("%s\n", string_to_print);
			command_is_valid = 1;
		}
		if (strcmp(command[0], "list") == 0 && command[1][0] >= '0' && command[1][0] <= '9') {
			listSturdinessAscending(console_pointer->the_controller, command[1], string_to_print);
			printf("%s\n", string_to_print);
			command_is_valid = 1;
		}
		if (strcmp(command[0], "list") == 0 && command[1][0] == '-') {
			if (command[1][1] == 'a' || command[1][1] == 'A') {
				listSturdinessAscending(console_pointer->the_controller, command[2], string_to_print);
				printf("%s\n", string_to_print);
				command_is_valid = 1;
			}
			if (command[1][1] == 'd' || command[1][1] == 'D') {
				listSturdinessDescending(console_pointer->the_controller, command[2], string_to_print);
				printf("%s\n", string_to_print);
				command_is_valid = 1;
			}
			
		}
		if (strcmp(command[0], "exit") == 0) {
			break;
		}
		if (command_is_valid == 0) {
			printf("Unrecognised command!\n\n");
		}
	}
}