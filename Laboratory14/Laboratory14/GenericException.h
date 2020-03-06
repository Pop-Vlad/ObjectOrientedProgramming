#pragma once

#include <exception>
#include <string>



class GenericException : std::exception {


private:

	std::string message;


public:

	//Create an exception
	//Arguments - (string) message
	GenericException(std::string init_message) : message(init_message) {};

	//Get the message of the exception
	//Arguments - None
	//Return - (char*) the message of the exception
	virtual const char* what() const noexcept override {
		return this->message.c_str();
	}


};