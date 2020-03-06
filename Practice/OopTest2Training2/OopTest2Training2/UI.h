#pragma once

#include "Controller.h"

#include <iostream>
#include <sstream>



class UI {


private:

	Controller controller;

	std::vector<std::string> getCommand();

public:

	UI(const Controller& input_controller) : controller(input_controller) {};

	void run();
	

};

