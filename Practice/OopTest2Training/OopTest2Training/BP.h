#pragma once

#include "MedicalAnalysis.h"



class BP : public MedicalAnalysis {


private:

	int systolicValue;

	int diastolicValue;


public:

	BP(const std::string& date, const int& systolic_value, const int& diastolic_value);

	bool isResultOK() const override;

	std::string toString() const override;
};