#include "Person.h"



void Person::addAnalysis(MedicalAnalysis* a) {
	this->analises.push_back(a);
}

std::vector<MedicalAnalysis*> Person::getAllAnalyses() const {
	return this->analises;
}

std::vector<MedicalAnalysis*> Person::getAnalysesByMonth(const int& month) const {
	std::vector<MedicalAnalysis*> filtered_analyses;
	for (int i = 0; i < this->analises.size(); i++) {
		if (this->analises[i]->getMonth() == month) {
			filtered_analyses.push_back(this->analises[i]);
		}
	}
	return filtered_analyses;
}

bool Person::isIll(const int& month) const {
	bool check = false;
	for (int i = 0; i < this->analises.size(); i++) {
		if (this->analises[i]->getMonth() == month) {
			check = true;
			if(!this->analises[i]->isResultOK()) {
				return false;
			}
		}
	}
	return check;
}

std::vector<MedicalAnalysis*> Person::getAnalysesBetweenDates(const std::string& date1, const std::string& date2) const {
	std::vector<MedicalAnalysis*> filtered_analyses;
	for (int i = 0; i < this->analises.size(); i++) {
		if (this->analises[i]->toString() >= date1 && this->analises[i]->toString() <= date2) {
			filtered_analyses.push_back(this->analises[i]);
		}
	}
	return filtered_analyses;
}

void Person::writeToFile(const std::string& filename, const std::string& date1, const std::string& date2) const {
	std::ofstream file;
	file.open(filename);

	for (int i = 0; i < this->analises.size(); i++) {
		file << this->analises[i]->toString() << " " << this->analises[i]->isResultOK() << "\n";
	}

	file.close();
}