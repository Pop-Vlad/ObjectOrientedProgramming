#include "Controller.h"



class Console {


private:

	Controller* controller;

	void readCommand();


public:

	Console(Controller* controller);

	void run();
	

};