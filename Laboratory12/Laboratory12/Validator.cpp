#include "Validator.h"



bool Validator::validateId(const std::string& id_to_validate) {
	return id_to_validate.size() >= 1;
}


bool Validator::validateSize(const std::string& size_to_validate) {
	return size_to_validate.size() >= 1;
}


bool Validator::validateInfecton(const std::string& infection_to_validate) {
	double result = std::stod(infection_to_validate);
	return result > 0;
}


bool Validator::validateMicrofragments(const std::string& microfragments_to_validate) {
	int result = std::stoi(microfragments_to_validate);
	return result > 0;
}


bool Validator::validatePhoto(const std::string& photo_to_validate) {
	return photo_to_validate.size() >= 1;
}


bool Validator::validateInput(const std::vector<std::string>& arguments) {
	try {
		if (arguments.size() == 0) {
			return false;
		}
		if (arguments[0] == "add" || arguments[0] == "update") {
			if (arguments.size() != 6) {
				return false;
			}
			return this->validateId(arguments[1]) && this->validateSize(arguments[2]) && this->validateInfecton(arguments[3])
				&& this->validateMicrofragments(arguments[4]) && this->validatePhoto(arguments[5]);
		}
		else if (arguments[0] == "delete" || arguments[0] == "save") {
			if (arguments.size() != 2) {
				return false;
			}
			return this->validateId(arguments[1]);
		}
		else if (arguments[0] == "fileLocation" || arguments[0] == "mode") {
			return arguments.size() >= 2;
		}
		else if (arguments[0] == "list") {
			if (arguments.size() == 1) {
				return true;
			}
			else {
				return (arguments.size() == 3) && this->validateSize(arguments[1]) && this->validateMicrofragments(arguments[2]);
			}
		}
		return true;
	}
	catch (std::exception) {
		return false;
	}
}