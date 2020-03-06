#pragma once

#include "ElectricEngine.h"
#include "TurboEngine.h"


class Pod {


private:

	std::string bodyStyle;

	Engine* engine;


public:

	Pod(const std::string& input_body_style, Engine* input_engine) : bodyStyle(input_body_style), engine(input_engine) {};
	
	double computePrice();

	std::string toString() { return "Pod: " + this->bodyStyle + " ,Engine: {" + this->engine->toString() + "} ,Total Price: " +
		std::to_string(this->computePrice()); }
};

