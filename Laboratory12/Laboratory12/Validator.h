#pragma once

#include "Controller.h"
#include "GenericException.h"

#include <vector>



class Validator {


public:

	Validator() {};

	bool validateId(const std::string& id_to_validate);

	bool validateSize(const std::string& size_to_validate);

	bool validateInfecton(const std::string& infection_to_validate);

	bool validateMicrofragments(const std::string& microfragments_to_validate);

	bool validatePhoto(const std::string& photo_to_validate);

	bool validateInput(const std::vector<std::string>& arguments);


};


typedef GenericException ValidationError;