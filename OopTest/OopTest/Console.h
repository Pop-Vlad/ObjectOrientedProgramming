#include "Controller.h"

#include <iostream>



class Console {


private:

	Controller* controller;

	void readCommand(char* command, char* parameter);


public:

	Console(Controller* controller);

	void run();


};