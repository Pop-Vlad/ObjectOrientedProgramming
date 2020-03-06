#pragma once

#include <iostream>
#include <string>

#include "Controller.h"

using namespace std;



class Console {


private:

	Controller* controller;

	void readCommand(char command[20], char parameters[5][20]);


public:

	Console(Controller* controller);

	~Console();

	void run();


};