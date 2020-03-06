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

	void printMenu() const;


public:

	Console(Controller* contrl) :controller(contrl) {};

	void run();


};