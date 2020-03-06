#include "UI.h"



void UI::run() {
	std::vector<std::string> arguments;
	while (true) {
		arguments = this->readCommand();
		if (arguments[0] == "add") {
			if (arguments[1] == "BMI") {
				BMI* new_analysis = new BMI{ arguments[2], std::stod(arguments[3]) };
				this->person.addAnalysis(new_analysis);
			}
			if (arguments[1] == "BP") {
				BP* new_analysis = new BP{ arguments[2], std::stoi(arguments[3]), stoi(arguments[4]) };
				this->person.addAnalysis(new_analysis);
			}
		}
		else if (arguments[0] == "list") {
			std::vector<MedicalAnalysis*> analyses = this->person.getAllAnalyses();
			for (std::vector<MedicalAnalysis*>::iterator iterator = analyses.begin(); iterator != analyses.end(); iterator++) {
				MedicalAnalysis* current_analysis = *iterator;
				std::cout << "	" << current_analysis->toString() << "\n";
			}
		}
		else if (arguments[0] == "ill") {
			if (this->person.isIll(stoi(arguments[1].substr(5, 2)))) {
				std::cout << "	Yes\n";
			}
			else {
				std::cout << "	No\n";
			}
		}
		else if (arguments[0] == "save") {
			this->person.writeToFile(arguments[1], arguments[2], arguments[3]);
		}
		else if (arguments[0] == "exit") {
			return;
		}
		else {
			std::cout << "	Unrecognise input\n";
		}
	}
}


std::vector<std::string> UI::readCommand() const {
	std::cout << ">>>";
	std::string input;
	std::getline(std::cin, input);
	std::stringstream command{ input };
	std::string parameter;
	std::vector<std::string> arguments;
	while (std::getline(command, parameter, ' ')) {
		arguments.push_back(parameter);
	}
	return arguments;
}