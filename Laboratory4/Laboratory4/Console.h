#pragma once
#include "Controller.h"
#include "Controller2.h"


typedef struct {
	controller* the_controller;
} console;


console* createConsole(controller* controller_pointer);

void destroyConsole(console* console_pointer);

void run(console* console_pointer);