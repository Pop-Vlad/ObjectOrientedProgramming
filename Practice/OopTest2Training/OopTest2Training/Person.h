#pragma once

#include "BMI.h"
#include "BP.h"

#include <vector>
#include <fstream>



class Person {


private:

	std::string name;

	std::vector<MedicalAnalysis*> analises;


public:

	Person(const std::string& person_name) : name(person_name) {};

	void addAnalysis(MedicalAnalysis* a);

	std::vector<MedicalAnalysis*> getAllAnalyses() const;

	std::vector<MedicalAnalysis*> getAnalysesByMonth(const int& month) const;

	bool isIll(const int& month) const;

	std::vector<MedicalAnalysis*> getAnalysesBetweenDates(const std::string& date1, const std::string& date2) const;

	void writeToFile(const std::string& filemane, const std::string& date1, const std::string& date2) const;


};