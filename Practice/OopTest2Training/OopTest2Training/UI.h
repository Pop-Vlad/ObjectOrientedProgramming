#pragma once

#include "Person.h"

#include <iostream>
#include <sstream>



class UI {

private:

	Person person;

public:

	UI(const Person& init_person) : person(init_person) {}

	void run();

	std::vector<std::string> readCommand() const;
};