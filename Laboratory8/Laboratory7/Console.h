#pragma once

#include <iostream>

#include "Controller.h"



class Console {


private:

	Controller* controller;

	void readCommand(char command[20], char parameters[5][20]);

	AnomalousFragment* createFragment(char* input_id, char* input_size, char* input_infection_level, char* input_microfragments, char* input_photograph);


public:

	Console(Controller* controller);

	~Console();

	void run();


};