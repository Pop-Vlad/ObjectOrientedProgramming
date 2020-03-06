#pragma once

#include "Controller.h"
#include "GenericException.h"

#include <vector>



class Validator {


public:

	//Create a validatior object
	Validator() {};

	//Check if an input is a valid AnomalousFragment id
	//Arguments - (string) id_to_validate = the input to check
	bool validateId(const std::string& id_to_validate);

	//Check if an input is a valid AnomalousFragment size
	//Arguments - (string) size_to_validate = the input to check
	bool validateSize(const std::string& size_to_validate);

	//Check if an input is a valid AnomalousFragment infection
	//Arguments - (string) infection_to_validate = the input to check
	bool validateInfecton(const std::string& infection_to_validate);

	//Check if an input is a valid AnomalousFragment number of microfragments
	//Arguments - (string) microfragments_to_validate = the input to check
	bool validateMicrofragments(const std::string& microfragments_to_validate);

	//Check if an input is a valid AnomalousFragment photo
	//Arguments - (string) photo_to_validate = the input to check
	bool validatePhoto(const std::string& photo_to_validate);

	//Check if an array of inputs can construct a valid AnomalousFragment
	//Arguments - (vector<string>) arguments
	bool validateInput(const std::vector<std::string>& arguments);


};


typedef GenericException ValidationError;