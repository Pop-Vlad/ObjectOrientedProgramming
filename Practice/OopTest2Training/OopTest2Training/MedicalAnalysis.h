#pragma once

#include <string>



class MedicalAnalysis {


protected:

	std::string date;


public:

	MedicalAnalysis() {}

	virtual bool isResultOK() const = 0;

	virtual std::string toString() const = 0;

	int getMonth() const { return std::stoi(this->date.substr(5, 2)); }


};