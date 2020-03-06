#include "BMI.h"



BMI::BMI(const std::string& date, const double& value) {
	this->date = date;
	this->value = value;
}


bool BMI::isResultOK() const {
	return (this->value > 18.5) && (this->value < 25);
}


std::string BMI::toString() const {
	std::string return_string = "BMI - Date: " + this->date + "; Value: " + std::to_string(this->value);
	return return_string;
}