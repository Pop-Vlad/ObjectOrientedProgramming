#pragma once

#include "MedicalAnalysis.h"



class BMI : public MedicalAnalysis {


private:

	double value;


public:

	BMI(const std::string& date, const double& value);

	bool isResultOK() const override;

	std::string toString() const override;
};