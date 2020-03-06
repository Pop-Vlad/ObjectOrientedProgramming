#pragma once

#include "Controller.h"
#include "Validator.h"

#include <iostream>
#include <string>
#include <windows.h>



class Console {


private:

	Controller* controller;

	std::vector<std::string> readCommand() const;

	//Print the menu of possible commands
	void printMenu() const;


public:

	//Create a console
	//Arguments - (Controller) the controller with which the ui works
	Console(Controller* contrl) :controller(contrl) {};

	//Run the console
	void run();


};