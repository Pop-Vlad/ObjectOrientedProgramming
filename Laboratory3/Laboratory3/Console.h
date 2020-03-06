#pragma once
#include "Controller.h"


typedef struct {
	controller* the_controller;
} console;


console* createConsole(controller* controller_pointer);

void destroyConsole(console* console_pointer);

void readCommand(char command[5][20]);

void run(console* console_pointer);