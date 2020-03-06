#include "BP.h"



BP::BP(const std::string& date, const int& systolic_value, const int& diastolic_value) {
	this->date = date;
	this->systolicValue = systolic_value;
	this->diastolicValue = diastolic_value;
}


bool BP::isResultOK() const {
	return (this->systolicValue > 90) && (this->systolicValue < 199) && (this->diastolicValue > 60) && (this->diastolicValue < 79);
}


std::string BP::toString() const {
	std::string return_string = "BP - Date: " + this->date + "; Systolic value: " + std::to_string(this->systolicValue) + "; Diastolic value: "
		+ std::to_string(this->diastolicValue);
	return return_string;
}