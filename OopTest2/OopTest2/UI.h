#pragma once

#include "Controller.h"

#include <iostream>
#include <sstream>



class UI {


private:

	Controller* controller;

	std::vector<std::string> getCommand();


public:

	UI(Controller* input_controller);

	void run();


};

